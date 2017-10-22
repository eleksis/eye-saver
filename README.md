# eye-saver
Mini program (written in C) to remind you to take breaks during work. It runs in background and will pop-up a new black 
window on your screen. 

## How it works
The idea is to have a few shorter breaks, for example every 20 minutes, each one lasting 3 minutes.
And after a couple of short ones you want one long break (let's say after 2 hours ~ after 6 short breaks).

## How to customize it
With these variables you can set how frequent and how long breaks you want.

small_break = 180;  # Duration of short break

long_break = 1200;  # Short break frequency (and at the same time duration of long break)

sm_goal = 4;        # After how many short breaks you want long one
