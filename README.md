## fdf

"fdf" is a simple Wireframe Viewer, i implemented [rotation matrices](https://en.wikipedia.org/wiki/Rotation_matrix) so you can move the maps in 3d.
You can see the [subject](https://github.com/adandres/fdf/blob/main/fdf.pdf) here.
Works only on Mac OsX

## Installation of fdf

To clone and compile the project, run:
```bash
 git clone https://github.com/adandres/fdf.git fdf && cd fdf && make
```
fdf builds with gcc.

## Usage

To launch the program type:
```bash
./fdf Map/france.l
```

Key|Action|
:-:|:-:
<kbd>c</kbd>|Select height coloration (recommended)
<kbd>m</kbd>|Select in depth height coloration (recommended)
<kbd>^</kbd><kbd>v</kbd>|Zoom
<kbd>z</kbd><br><kbd>q</kbd><kbd>s</kbd><kbd>d</kbd>|Move
<kbd>Shift</kbd>| Rotate map to bird's eye view
<kbd>Space</kbd>| Rotate map to initial view
<kbd>ù</kbd>| Select mouse rotation
<kbd>^</kbd><kbd>$</kbd>|Change water elevation
<kbd>a</kbd><kbd>e</kbd>|Rotate map on X axis
<kbd>u</kbd><kbd>o</kbd>|Rotate map on Y axis
<kbd>f</kbd><kbd>v</kbd>|Rotate map on Z axis
<kbd>ESC</kbd>|Quit the program


## Note
25/20

![exemple](/images/exemple.jpg)
