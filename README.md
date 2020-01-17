Why
-
Because it looks nice

How
-
There are two methods that could be used.


1) Changing all the fixed timestep functions to use different variables. For example, multiplying the an entity's velocity by 0.5 when calculating the new position allows for the game to run at 60fps without speeding up. Some integers would need to be changed to floats as well.

2) Using linear interpolation so that the game is updated at 30fps, but is rendered at above 30fps.

I am using Method 2, as method 1 involves too many variables for me to find.

Method 2 has a disadvantage of 1/30th of a second worth of latency.

Exterpolation could maybe be used instead to solve this at the disadvantage of wrong predictions.

What works
-
All entities that move are interpolated (this is done by updating their old position before they are moved)

All backgrounds that move use deltatime

Variables set related to colour/animations/flashing/screenshake/messageboxes/glitched level names have been moved from the new variable render function to fixed render function.

Creation of entities sets more variables to be more accurate needed to avoid inaccurate rendering for first frame (this includes old position, animation frames, colour transform, and spawning of "LIES" and clouds being slightly off)

Screen wrapping updates the old position so that the player doesn't very quickly move across the screen to get to the other side

The Tower "map" is interpolated

The game logic function and the game fixed render functions have been swapped, meaning logic is now processed before rendering

What doesn't work
-
Anything that's not in gamestate GAMEMODE does not render over 30 fps (NOT PLANNING ON DOING)

Running the game at a slower fixed speed than 30 using slowmode probably does not alter deltatime when it should (not tested)

"huge hero" in Secret Lab cutscene not interpolated, old position isn't updated during cutscene (edit: previous statement might no longer be the case) so can't easily use a lerp

Swiping transitions during gameplay are at 30 fps which I might be able to easily improve

entering the tower, tower glitched for 1 frame

and things that have not been tested yet might not work

Bugs that occur in the original game still occur, I'm not planning on fixing these.

What's been tested
-
100% of the main game.
The secret lab.
3 Time Trials
any% of the main game flipped
1 Time Trial flipped

When are you going to update it
-
I am busy working on University stuff but if I have free time and feel like I want to update it then I will
