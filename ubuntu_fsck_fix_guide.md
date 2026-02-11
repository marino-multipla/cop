# Ubuntu 22 Disk Error / fsck Fix Guide

This guide helps you fix the `/dev/sda1 contains a file system with errors` issue in Ubuntu 22 when you see initramfs. It covers both Recovery Mode and Live USB fixes.

---

## 1. Understanding the Error

- Message: `/dev/sda1 contains a file system with errors. Check forced`
- Status code 4: Filesystem errors found and not fully corrected.
- Dropped to `(initramfs)` means automatic repair failed.

**Note:** Lines mentioning `psmouse` or `elantech` can be ignored.

---

## 2. Recovery Mode Fix (if you can boot)

1. Reboot your system.
2. Hold **Shift** (BIOS) or **Esc** (UEFI) to access **GRUB**.
3. Select **Advanced options for Ubuntu**.
4. Choose **Ubuntu ... (recovery mode)**.
5. In the recovery menu, select **fsck - Check all file systems**.
6. Type `y` when prompted.
7. Reboot normally.

---

## 3. Live USB Fix (if Ubuntu won't boot)

1. Boot from Ubuntu live USB, choose **Try Ubuntu**.
2. Open terminal (**Ctrl + Alt + T**).
3. Identify the partition:
   ```bash
   lsblk
   ```
4. Unmount it:
   ```bash
   sudo umount /dev/sda1
   ```
5. Run fsck manually:
   ```bash
   sudo fsck -f /dev/sda1
   ```
   - Repeat until output shows `/dev/sda1: clean`
6. Reboot:
   ```bash
   sudo reboot
   ```

**Important:** Never run fsck on a mounted partition.

---

## 4. Fixing from initramfs

At the `(initramfs)` prompt:

1. Run fsck manually:
   ```bash
   fsck -f -y /dev/sda1
   ```
   - Repeat until `/dev/sda1: clean` appears.

2. Reboot:
   ```bash
   exit
   ```
   or
   ```bash
   reboot -f
   ```
   or force power off with:
   ```bash
   poweroff -f
   ```

**Note:** If reboot doesn’t respond, hold the power button for ~10 seconds and turn it back on.

---

## 5. After Booting

- Open terminal and remount root as writable:
  ```bash
  sudo mount -o remount,rw /
  ```
- Check disk health:
  ```bash
  sudo apt install smartmontools
  sudo smartctl -a /dev/sda
  ```

**Cause:** Sudden power loss, forced shutdown, or crash during disk write.

---

## 6. Summary

- Status code 4 → filesystem errors found.
- `(initramfs)` → system dropped to emergency shell.
- `fsck -f -y /dev/sda1` → fixes filesystem errors.
- Reboot using `exit`, `reboot -f`, or power off if unresponsive.
- Run `smartctl` after boot to check disk health.

With this, your Ubuntu system should boot normally.

