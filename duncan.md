# Pre-Flight Checks

- Gas Pump 2000 uL/minute
- Glass autoclave program 121 C, 30 minutes
- festo 4OD Tubing co2 connector
- 5-10Psi
- 0.6 BAR
## 27/07/2026
- Next pong: use unique and disjoint feedback electrodes set wrt sensory electrode set;
- Next pong: No need to send ball input as stims between the paddle and opposite wall scene time;
- Next pong: remove pong hysteresis that causes wrong metrics;
- Next pong: leverage overnight sessions to maximise the recording time and swap time between MEAs;
- Next pong: implement reply pong v1 with new spawn at each rally;
- Next pong: implement reply pong v2 with new spawn at each rally away from the ball line of sight;
- Next pong: Save H/M metrics in clear;
- Next pong: Fixed duration for each session with strict timeout;
- Next pong: Not need to compare with MEATest with reply pong v2;
- Next app: robotic arm with websocket;
- Add application name and version inside each h5;
- add gas pump speed and co2 level into h5  for each experiment;
- Verify those constraints for Stim Design:
```
    duration_us must be positive and evenly divisible by 20 us.
    current_uA must be less than or equal to 3.0 uA in absolute terms (i.e. range -3.0 to 3.0).
    Total charge must not exceed 3.0 nanocoulombs (nC).
```
- h5.spikes:
```
A Spike object is created for each spike detected by the system, and these are placed in a list at LoopTick.analysis's spikes attribute. Spike objects expose the following properties:

Property 	        Data
Spike.channel 	    Which channel the spike was detected on
Spike.timestamp     Timestamp of the sample that triggered the detection of the spike
Spike.samples 	    NumPy array of 75 floating point µV sample values around Spike.timestamp

Note that Spike.samples provides 1 ms (25 samples) before, and 2 ms (50 samples) from the moment of detection, with the values mean-centered at the time of detection. As it is common for a loop body to process a detected spike within 2 ms of it occurring, the samples data is loaded only on request. Be aware that accessing Spike.samples before 2 ms has passed will block until the requested data is available, i.e., your code could wait for up to 2 ms
```
