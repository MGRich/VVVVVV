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

What doesn't work
-
Moving platforms cause player to jitter when on them

Threadmills are cause player to jitter when on them

Changing colours happens at over 30fps when it should only happen at 30fps to make colours stand out more

Gravity lines flash too fast

Anything that's not in gamestate GAMEMODE does not render over 30 fps

"huge hero" in Secret Lab cutscene not interpolated, old position isn't updated during cutscene so can't easily use a lerp

"The Cuckoo" and a few rooms after it have "Lies" that move downwards for 1 frame (along with clouds that move rightwards for 1 frame)

Hardest room doesn't display

and things that have not been tested yet might not work

What's been tested
-
100% of the main game.
The secret lab.

When are you going to update it
-
I am busy working on University stuff but if I have free time and feel like I want to update it then I will
