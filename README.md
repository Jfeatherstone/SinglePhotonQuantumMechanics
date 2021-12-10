## Single Photon Quantum Mechanics

![interferometer image](https://github.com/Jfeatherstone/SinglePhotonQuantumMechanics/blob/master/Diagrams/Optical_Table_Diagram_Interferometer.png)

This repo contains various resources for the undergraduate single photon experiments at NC State, based on the work of Kiko Galvez [1] and others. The general idea is to demonstrate "modern" quantum phenomena, like entanglement and quantum teleportation, using photons generated from spontaneous parametric down-conversion (SPDC) [2]. For a more technical overview of this process, as well as some experimental specifications, see the included paper: [Single photon quantum mechanics for undergraduates](https://github.com/Jfeatherstone/SinglePhotonQuantumMechanics/blob/master/manuscript.pdf)

## Power Supply

The `PowerSupply/` folder contains most of the relevant information about the power supply we have built for the avalanching photodetectors. This device is controlled by an Arduino board, and will cut power to the detectors if there is too much ambient light (which could burn out the detector plates). A wiring diagram is included in the lab notebook, but has not been digitized yet.

## Figures

The `Diagrams/` folder contains all of the vector graphics I have drawn for this project, included beam paths, devices, or whatever else. I've included both .svg and .png files for most images. If you'd like to edit them, it may help to know that (most of?) the isometric images are angled at 20 degrees.

Feel free to use these as you'd like.

## Bibliography

I've included the bib file that contains a lot of relevant references for this project, both about SPDC/single photons and the role of laboratories in the classroom.

### References

[1] Galvez, E. J. (2014). Resource Letter SPE-1: Single-Photon Experiments in the Undergraduate Laboratory. American Journal of Physics, 82(11), 1018–1028. https://doi.org/10.1119/1.4872135

[2] Couteau, C. (2018). Spontaneous parametric down-conversion. Contemporary Physics, 59(3), 291–304. https://doi.org/10.1080/00107514.2018.1488463

