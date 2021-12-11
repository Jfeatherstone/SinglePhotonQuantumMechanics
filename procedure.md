## Experimental Procedure

### General Setup

1. Turn on dev board (green led in top right should blink at 10Hz) and put the BBO crystal into its holder (it is kept in a container with dessicant normally).
2. Open LabView software, and connect RS232 adapter to PC.
3. Select the proper COM port in Labview (mine is COM3, but may vary).
4. Unplug the power cables from the single photon detectors (not totally necessary, but just to be safe).
5. Turn on variable power supply that plugs into the custom power supply (that protects detectors), and make sure it is set to 5V. The light should turn dark blue, or teal if the lights are off. If the LED is green, that means power is actively being supplied to the cables to the detectors.
6. Plug the power cables back into the single photon detectors (again, make sure the indicator LED is NOT green on the safety power supply).
7. Turn on the blue pump laser, with the cap over the diode.
8. Turn off all lights in the room; the status indicator on the power supply should turn teal.
9. Press power button on the power supply to start up the detectors. You should see a current of 1 amp drawn for each detector plugged in, which will lower to about half an amp after a second or two. You should see the dark count of ~500 counts/second on the Labview display.
10. Uncap the diode laser, and you hopefully should see a jump in counts from the signal detector .

### Interference Experiment

1. Using a pinhole light (can be made by taping a piece of paper with a small hole over your phone camera), square up the interferometer arms, following the procedure in [1].
2. Make sure the flipper mirror that redirects one beam to the interferometer is active (do not flip it while the laser is active though).
3. Turn on the alignment laser, and make sure that it is properly redirected through the interferometer. The two beam images should be mostly on top of each other after exiting the interferometer.
4. Place the spectrometer such that the interfering light is read in.
5. Open the Vernier Spectral Analysis software. If you see ringing across the spectrum of light, that means the arms are close in length. If you don't see ringing, try adjusting the linear stage on one corner of the interferometer until you do see it.
6. Adjust the linear stage to maximize the period of the ringing.
7. It is quite hard to judge when you get close, because you will need to identify constructive/destructive interference across the entire spectrum.
8. You can test the piezo at this point, by sweeping it across the voltage range 0-24V. You should see some change in the extent of interference on the spectrometer reading.
9. Move the spectrometer out of the way, and turn on the blue laser and avalanching detectors (as described above)
10. You should see a good amount of photon counts (~5000) which will hopefully change as you sweep the piezo voltage.
11. Don't be discouraged if you don't see a change in the number of counts; the down converted light has a much shorter coherence length than the alignment laser, meaning the former case is much more sensitive to the equal arm condition.
12. Repeat steps 4-6 and try again with the single photons.

### References

[1] Price, E. W. (1952). Initial Adjustment of the Mach‐Zehnder Interferometer. Review of Scientific Instruments, 23(4), 162–162. https://doi.org/10.1063/1.1746214

