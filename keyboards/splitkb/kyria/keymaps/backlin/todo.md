# To-do
Use fixed backlight with hue and sat controlled by typing speed.

Typing speed can be calculated using the feature [Velocikey][]
(implemented in `quantum/velocikey.c`).

Velocikey maintains a typing speed counter that is accelerated at keypress
(`quantum/quantum.c:process_record_quantum()`) and decelerated as a routine task
(`tmk_core/common/keyboard.c:keyboard_task()`).
The counter is read by calling `velocikey_match_speed()`.


RGB underglow is controlled using the feature [RGB lighting][], not to be confused
with backlight (backlighted keys) or RGB matrix.

To figure out:

* Where to update the HSV values based on counter?
* How to control the two sides separately?


[RGB lighting]: https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight
[Velocikey]: https://beta.docs.qmk.fm/using-qmk/hardware-features/feature_velocikey.

# Small fixes
## Font
Redo ctrl and alt in Mac style
Make graphical progress bars for HSV

## OLED
Remove shift from config layer
Decrease space between chars so thumb cluster can also fit
Detect which half changed the layer, not just for the symbol layer
Make cooler graphics for right side

Check this out!
https://www.reddit.com/r/MechanicalKeyboards/comments/hq8jp5/made_a_wave_form_oled_display_of_how_fast_you_type/
