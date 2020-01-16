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

What works (todo make shorter)
-
Sprite entities use linear interpolation

"Really big sprite" entities use linear interpolation

2x1 entities (seemed to only be used in Boldly To Go) entities use linear interpolation

Moving platform entities use linear interpolation

All backgrounds (apart from The Tower) use deltatime, stars are stored using floats, Warp Zones no longer use surface (for now) thus less efficient

Animation frames are now updated in fixed timestep instead of in the render function

Creation of entities sets the old position variables to avoid initial zip

Message Boxes are only updated during fixed timesteps

Screen wrapping does not "zip", it updates the old position

The Tower, and entities inside the tower are interpolated, including gravity lines. The background is interpolated and doesn't use surface (see Warp Zones above)

Entities drawframe is set to entities tile apon creation, this stops them having the sprite of the player for the first frame.

Gravitron entities are interpolated, and their old position is updated when getting the enemies offscreen

Death/Complete Stops update the old position of entities to avoid interpolation jitter

The colour cycling for the final level are only updated during fixed timesteps

Anomaly and Purest Unobtainium backgrounds are only updated during fixed timesteps

Entities old positions are now updated before the input function, meaning that when the player is on a treadmill/moving platform

The game logic function and the game fixed render functions have been swapped, meaning logic is now processed before rendering

Entities and teleporters store their colour and update it at a fixed framerate instead of every time they are rendered (makes colours stand out more)

The glitched level name getter is now called in the fixed render function so that the glitched level name can be seen better

Gravity line flashing is updated in fixed render function

"LIES" and clouds are spawned with their old position set to the spawn position so that they aren't off by a few pixels during first render

What doesn't work
-
Enemies that move back and forth stutter for a frame or two when they reach their turning point (todo: test again)

Anything that's not in gamestate GAMEMODE does not render over 30 fps

"huge hero" in Secret Lab cutscene not interpolated, old position isn't updated during cutscene (edit: previous statement might no longer be the case) so can't easily use a lerp

Hardest room doesn't display (todo: test again)

and things that have not been tested yet might not work

What's been tested before old positions were updated before the input function and before the fixed render function and the logic function were swapped
-
100% of the main game.
The secret lab.
3 Time Trials

What's been tested after the two big changes mentioned above were implemented
-
The final Time Trial

When are you going to update it
-
I am busy working on University stuff but if I have free time and feel like I want to update it then I will
