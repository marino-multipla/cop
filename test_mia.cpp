/*
 * Standalone Mia Hand thumb open/close test (NO ROS).
 *
 * Build:
 *   mkdir -p build && cd build
 *   cmake .. && cmake --build . -j
 *
 * Run (examples):
 *   ./test_mia --port /dev/ttyUSB0
 *   ./test_mia --port /dev/ttyUSB1 --cycles 10 --speed 60 --current 60
 */

#include "mia_hand_driver/cpp_driver.h"

#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>

namespace
{
void usage(const char* argv0)
{
  std::cerr
    << "Standalone Mia Hand thumb open/close test (no ROS)\n\n"
    << "Usage:\n"
    << "  " << argv0 << " [options]\n\n"
    << "Options:\n"
    << "  --port <dev>        Serial port (default: /dev/ttyUSB0)\n"
    << "  --cycles <n>        Number of open/close cycles (default: 5)\n"
    << "  --current <0..80>   Max current percent (default: 70)\n"
    << "  --open-pos <0..255> Thumb OPEN motor position (default: 20)\n"
    << "  --close-pos <0..255> Thumb CLOSE motor position (default: 200)\n"
    << "  --traj-spe <0..99>  Trajectory speed/force percent (default: 50)\n"
    << "  --close-ms <ms>     Time spent closing (default: 1000)\n"
    << "  --open-ms <ms>      Time spent opening (default: 1000)\n"
    << "  --pause-ms <ms>     Pause between motions (default: 300)\n"
    << "  --pre-wait-ms <ms>  Wait after initial reads (default: 5000)\n"
    << "  --calibrate         Run motor-position calibration before moving\n"
    << "  --cal-wait-ms <ms>  Wait after calibration trigger (default: 4000)\n"
    << "  -h, --help          Show this help\n";
}

bool argEquals(const std::string& a, const char* b) { return a == b; }

int toInt(const std::string& s)
{
  try
  {
    size_t idx = 0;
    int v = std::stoi(s, &idx, 10);
    if (idx != s.size())
    {
      throw std::invalid_argument("trailing");
    }
    return v;
  }
  catch (...)
  {
    throw std::runtime_error("Invalid integer: " + s);
  }
}

bool reopenAndResync(mia_hand::CppDriver& drv, const std::string& port)
{
  // Best-effort: closing may fail if already closed; ignore.
  (void)drv.closeSerialPort();
  std::this_thread::sleep_for(std::chrono::milliseconds(150));

  if (!drv.openSerialPort(port))
  {
    std::cerr << "Reopen failed on " << port << ": " << drv.getErrorMsg() << "\n";
    return false;
  }

  drv.play();
  if (!drv.isConnected())
  {
    std::cerr << "Resync failed (no ACK) on " << port << ": " << drv.getErrorMsg() << "\n";
    return false;
  }

  return true;
}
}  // namespace

int main(int argc, char** argv)
{
  std::string port = "/dev/ttyUSB0";
  int cycles = 5;
  int current = 70;
  int open_pos = 20;
  int close_pos = 200;
  int traj_spe = 50;
  int close_ms = 1000;
  int open_ms = 1000;
  int pause_ms = 300;
  int pre_wait_ms = 5000;
  bool do_calibrate = false;
  int cal_wait_ms = 4000;

  for (int i = 1; i < argc; ++i)
  {
    const std::string a = argv[i];
    if (argEquals(a, "-h") || argEquals(a, "--help"))
    {
      usage(argv[0]);
      return 0;
    }
    if ((argEquals(a, "--port") || argEquals(a, "--cycles") || argEquals(a, "--current") ||
         argEquals(a, "--open-pos") || argEquals(a, "--close-pos") || argEquals(a, "--traj-spe") ||
         argEquals(a, "--close-ms") || argEquals(a, "--open-ms") || argEquals(a, "--pause-ms") ||
         argEquals(a, "--pre-wait-ms") ||
         argEquals(a, "--cal-wait-ms")) &&
        i + 1 >= argc)
    {
      std::cerr << "Missing value for " << a << "\n";
      usage(argv[0]);
      return 2;
    }

    if (argEquals(a, "--port"))
    {
      port = argv[++i];
    }
    else if (argEquals(a, "--cycles"))
    {
      cycles = toInt(argv[++i]);
    }
    else if (argEquals(a, "--current"))
    {
      current = toInt(argv[++i]);
    }
    else if (argEquals(a, "--open-pos"))
    {
      open_pos = toInt(argv[++i]);
    }
    else if (argEquals(a, "--close-pos"))
    {
      close_pos = toInt(argv[++i]);
    }
    else if (argEquals(a, "--traj-spe"))
    {
      traj_spe = toInt(argv[++i]);
    }
    else if (argEquals(a, "--close-ms"))
    {
      close_ms = toInt(argv[++i]);
    }
    else if (argEquals(a, "--open-ms"))
    {
      open_ms = toInt(argv[++i]);
    }
    else if (argEquals(a, "--pause-ms"))
    {
      pause_ms = toInt(argv[++i]);
    }
    else if (argEquals(a, "--pre-wait-ms"))
    {
      pre_wait_ms = toInt(argv[++i]);
    }
    else if (argEquals(a, "--calibrate"))
    {
      do_calibrate = true;
    }
    else if (argEquals(a, "--cal-wait-ms"))
    {
      cal_wait_ms = toInt(argv[++i]);
    }
    else
    {
      std::cerr << "Unknown arg: " << a << "\n";
      usage(argv[0]);
      return 2;
    }
  }

  if (cycles <= 0)
  {
    std::cerr << "--cycles must be > 0\n";
    return 2;
  }

  if (current < 0) current = 0;
  if (current > 80) current = 80;
  if (open_pos < 0) open_pos = 0;
  if (open_pos > 255) open_pos = 255;
  if (close_pos < 0) close_pos = 0;
  if (close_pos > 255) close_pos = 255;
  if (traj_spe < 0) traj_spe = 0;
  if (traj_spe > 99) traj_spe = 99;
  if (pre_wait_ms < 0) pre_wait_ms = 0;

  auto drv = mia_hand::CppDriver::create();
  if (!drv)
  {
    std::cerr << "Failed to create CppDriver\n";
    return 1;
  }

  if (!drv->openSerialPort(port))
  {
    std::cerr << "Failed to open serial port " << port << ": " << drv->getErrorMsg() << "\n";
    return 1;
  }
  std::cerr << "Opened " << port << "\n";

  // Important: CppDriver's emergency_stop_on_ may be uninitialized; play() forces it off.
  drv->play();

  if (!drv->isConnected())
  {
    std::cerr << "No response from Mia Hand on " << port << ": " << drv->getErrorMsg() << "\n";
    drv->closeSerialPort();
    return 1;
  }
  std::cerr << "Mia Hand connected\n";

  // --- Initial reads (before calibration) ---
  bool need_resync = false;
  {
    const char* fw = drv->getFwVersion();
    if (fw && fw[0] != '\0')
    {
      std::cerr << "Firmware: " << fw;
      if (std::string(fw).back() != '\n')
      {
        std::cerr << "\n";
      }
    }
    else
    {
      std::cerr << "Firmware read failed: " << drv->getErrorMsg() << "\n";
      need_resync = true;
    }

    int32_t thumb_mpos = 0, index_mpos = 0, mrl_mpos = 0;
    int32_t thumb_mspe = 0, index_mspe = 0, mrl_mspe = 0;
    int32_t thumb_mcur = 0, index_mcur = 0, mrl_mcur = 0;
    double thumb_jpos = 0.0, index_jpos = 0.0, mrl_jpos = 0.0;
    double thumb_jspe = 0.0, index_jspe = 0.0, mrl_jspe = 0.0;
    int32_t thumb_nfor = 0, index_nfor = 0, mrl_nfor = 0;
    int32_t thumb_tfor = 0, index_tfor = 0, mrl_tfor = 0;

    if (drv->getMotorPositions(thumb_mpos, index_mpos, mrl_mpos))
    {
      std::cerr << "Motor pos: thumb=" << thumb_mpos << " index=" << index_mpos << " mrl=" << mrl_mpos << "\n";
    }
    else
    {
      std::cerr << "Motor pos read failed: " << drv->getErrorMsg() << "\n";
      need_resync = true;
    }

    if (drv->getMotorSpeeds(thumb_mspe, index_mspe, mrl_mspe))
    {
      std::cerr << "Motor spe: thumb=" << thumb_mspe << " index=" << index_mspe << " mrl=" << mrl_mspe << "\n";
    }
    else
    {
      std::cerr << "Motor spe read failed: " << drv->getErrorMsg() << "\n";
      need_resync = true;
    }

    if (drv->getMotorCurrents(thumb_mcur, index_mcur, mrl_mcur))
    {
      std::cerr << "Motor cur: thumb=" << thumb_mcur << " index=" << index_mcur << " mrl=" << mrl_mcur << "\n";
    }
    else
    {
      std::cerr << "Motor cur read failed: " << drv->getErrorMsg() << "\n";
      need_resync = true;
    }

    if (drv->getJointPositions(thumb_jpos, index_jpos, mrl_jpos))
    {
      std::cerr << "Joint pos(rad): thumb=" << thumb_jpos << " index=" << index_jpos << " mrl=" << mrl_jpos << "\n";
    }
    else
    {
      std::cerr << "Joint pos read failed: " << drv->getErrorMsg() << "\n";
      need_resync = true;
    }

    if (drv->getJointSpeeds(thumb_jspe, index_jspe, mrl_jspe))
    {
      std::cerr << "Joint spe(rad/s): thumb=" << thumb_jspe << " index=" << index_jspe << " mrl=" << mrl_jspe << "\n";
    }
    else
    {
      std::cerr << "Joint spe read failed: " << drv->getErrorMsg() << "\n";
      need_resync = true;
    }

    if (drv->getFingerForces(
          thumb_nfor, index_nfor, mrl_nfor,
          thumb_tfor, index_tfor, mrl_tfor))
    {
      std::cerr << "Forces: thumb(n,t)=(" << thumb_nfor << "," << thumb_tfor << ") "
                << "index(n,t)=(" << index_nfor << "," << index_tfor << ") "
                << "mrl(n,t)=(" << mrl_nfor << "," << mrl_tfor << ")\n";
    }
    else
    {
      std::cerr << "Forces read failed: " << drv->getErrorMsg() << "\n";
      need_resync = true;
    }
  }

  if (need_resync)
  {
    std::cerr << "One or more reads failed; re-syncing serial...\n";
    if (!reopenAndResync(*drv, port))
    {
      std::cerr << "Serial re-sync failed. Check cabling/port and try again.\n";
      return 1;
    }
    std::cerr << "Serial re-sync OK\n";
  }

  if (pre_wait_ms > 0)
  {
    std::cerr << "Waiting " << pre_wait_ms << " ms before calibration/motion...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(pre_wait_ms));
  }

  if (do_calibrate)
  {
    // Calibration is sensitive to any leftover bytes in the RX buffer.
    // Reopen the port to start from a clean stream.
    std::cerr << "Re-syncing before calibration...\n";
    if (!reopenAndResync(*drv, port))
    {
      std::cerr << "Pre-calibration re-sync failed.\n";
      return 1;
    }

    std::cerr << "Triggering motor position calibration...\n";
    if (!drv->calibrateMotorPositions())
    {
      std::cerr << "Failed to start calibration: " << drv->getErrorMsg() << "\n";
      drv->closeSerialPort();
      return 1;
    }
    std::cerr << "Calibration triggered. Waiting " << cal_wait_ms << " ms...\n";
    if (cal_wait_ms > 0)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(cal_wait_ms));
    }
    // Ensure we are not in emergency-stop state before moving.
    drv->play();
  }

  const uint32_t thumb_motor = 0;  // 0: thumb, 1: index, 2: mrl (per driver)

  auto sleepMs = [](int ms) {
    if (ms > 0)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }
  };

  auto setThumbTraj = [&](int target_pos) -> bool {
    return drv->setMotorTrajectory(thumb_motor, target_pos, traj_spe);
  };

  // Ensure we are in normal operation before moving.
  drv->play();

  std::cerr << "Starting cycles=" << cycles
            << " open_pos=" << open_pos
            << " close_pos=" << close_pos
            << " traj_spe=" << traj_spe
            << " current=" << current
            << "\n";

  for (int c = 1; c <= cycles; ++c)
  {
    std::cerr << "Cycle " << c << "/" << cycles << ": close\n";
    if (!setThumbTraj(close_pos))
    {
      std::cerr << "Failed to set thumb close trajectory: " << drv->getErrorMsg() << "\n";
      break;
    }
    sleepMs(close_ms);
    sleepMs(pause_ms);

    std::cerr << "Cycle " << c << "/" << cycles << ": open\n";
    if (!setThumbTraj(open_pos))
    {
      std::cerr << "Failed to set thumb open trajectory: " << drv->getErrorMsg() << "\n";
      break;
    }
    sleepMs(open_ms);
    sleepMs(pause_ms);
  }

  // Best-effort stop before exit (speed 0). If it fails, we still close the port.
  (void)drv->setMotorSpeed(thumb_motor, 0, current);
  drv->closeSerialPort();
  std::cerr << "Done\n";

  return 0;
}

