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

Moving platform entities use linear interpolation

Starfield background uses deltatime

Animation frames are now updated in fixed timestep instead of in the render function

Creation of entities sets the old position variables to avoid initial zip

What doesn't work
-
Tutorial messages

Entities have player sprite until the first fixed timestep after they are created

Death/trinkets causes anything interpolated to jitter

Moving platforms cause player to jitter when on them

Nothing is interpolated in The Tower

Many more things that have not been tested yet

What's been tested
-
Up to the first save point

When are you going to update it
-
I am busy working on University stuff but if I have free time and feel like I want to update it then I will
