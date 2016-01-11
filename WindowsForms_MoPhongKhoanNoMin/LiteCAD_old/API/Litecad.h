/********************************************************************
* Project: LiteCAD DLL
* Copyright (c) 2009-2013, Oleg Kolbaskin.
* All rights reserved.
*
* API definitions and external functions
********************************************************************/
#ifndef _LCAPI_H
#define _LCAPI_H

#define LC_FALSE    0  
#define LC_TRUE     1 

// Mouse buttons
#define LC_LBUTTON  1   // Left button is pressed
#define LC_RBUTTON  2   // right button is pressed
#define LC_MBUTTON  4   // middle button is pressed

// Key state
#define LC_SHIFT  1   // SHIFT key is pressed
#define LC_CTRL   2   // CTRL key is pressed
#define LC_ALT    4   // ALT key is pressed

// LiteCAD window styles
#define LC_WS_HSCROLL     1    // Window has a horizontal scroll bar
#define LC_WS_VSCROLL     2    // Window has a vertical scroll bar
#define LC_WS_BORDER      4    // Window has a thin-line border
#define LC_WS_CLIENTEDGE  8    
#define LC_WS_SUNKEN      8    // Window has a border with a sunken edge
#define LC_WS_STATICEDGE  16   // Window has a three-dimensional border style
#define LC_WS_VIEWTABS    256  // Window has View Tabs (border frame automatically added)
#define LC_WS_DEFAULT     3    // Combination of LC_WS_VSCROLL and LC_WS_HSCROLL styles

// LiteCAD window cursor, to use in lcPropPutInt(0, LC_PROP_G_CURSORARROW, Val)
#define LC_CURSOR_NULL    0    // no cursor
#define LC_CURSOR_ARROW   1    // Standard arrow
#define LC_CURSOR_CROSS   2    // Crosshair
#define LC_CURSOR_HAND    3    // Hand
#define LC_CURSOR_HELP    4    // Arrow and question mark
#define LC_CURSOR_NO      5    // Slashed circle
#define LC_CURSOR_WAIT    6    // Hourglass
#define LC_CURSOR_PAN1    7    // Pan start cursor
#define LC_CURSOR_PAN2    8    // Pan move cursor

// Drawing's units
#define LC_INSUNIT_UNDEFINED     0    // Undefined
#define LC_INSUNIT_INCHES        1    // Inches
#define LC_INSUNIT_FEET          2    // Feet
#define LC_INSUNIT_MILES         3    // Miles
#define LC_INSUNIT_MILLIMETERS   4    // Millimeters
#define LC_INSUNIT_CENTIMETERS   5    // Centimeters
#define LC_INSUNIT_METERS        6    // Meters
#define LC_INSUNIT_KILOMETERS    7    // Kilometers
#define LC_INSUNIT_MICROINCHES   8    // Microinches
#define LC_INSUNIT_MILS          9    // Mils
#define LC_INSUNIT_YARDS         10   // Yards
#define LC_INSUNIT_ANGSTROMS     11   // Angstroms
#define LC_INSUNIT_NANOMETERS    12   // Nanometers
#define LC_INSUNIT_MICRONS       13   // Microns
#define LC_INSUNIT_DECIMETERS    14   // Decimeters
#define LC_INSUNIT_DEKAMETERS    15   // Dekameters
#define LC_INSUNIT_HECTOMETERS   16   // Hectometers
#define LC_INSUNIT_GIGAMETERS    17   // Gigameters
#define LC_INSUNIT_ASTRONOMICAL  18   // Astronomical
#define LC_INSUNIT_LIGHTYEARS    19   // Lightyears
#define LC_INSUNIT_PARSECS       20   // Parsecs

#define LC_LUNIT_SCIEN  1  // Scientific
#define LC_LUNIT_DECIM  2  // Decimal
#define LC_LUNIT_ENGIN  3  // Engineering
#define LC_LUNIT_ARCHI  4  // Architectural
#define LC_LUNIT_FRACT  5  // Fractional

// Angle units used with GUI and API (variants for LC_PROP_G_ANGLE property)
#define LC_AUNIT_DEGREE  0  // Decimal degrees
#define LC_AUNIT_DMS     1  // Degrees/minutes/seconds
#define LC_AUNIT_GRAD    2  // Grads
#define LC_AUNIT_RADIAN  3  // Radians
#define LC_AUNIT_SURVEY  4  // Surveyor's units
// same
#define LC_ANGLE_DEGREE  0  // Decimal degrees
#define LC_ANGLE_DMS     1  // Degrees/minutes/seconds
#define LC_ANGLE_GRAD    2  // Grads
#define LC_ANGLE_RADIAN  3  // Radians
#define LC_ANGLE_SURVEY  4  // Surveyor's units

// angles in radians
#define LC_PI 3.14159265358979323846    // 180
#define LC_PI2 (LC_PI / 2.0)    // 1,57079632679489661923    90
#define LC_PI4 (LC_PI / 4.0)    // 0,785398163397448309615   45
#define LC_2PI (LC_PI+LC_PI)    // 6,28318530717958647692   360

// aka degrees
#define LC_DEG45   LC_PI4
#define LC_DEG90   LC_PI2
#define LC_DEG180  LC_PI
#define LC_DEG270  (LC_PI+LC_PI2)
#define LC_DEG360  LC_2PI

// Radian -> Degree
#define LC_RAD_TO_DEG    57.2957795130823208
// Degree -> Radian
#define LC_DEG_TO_RAD    0.0174532925199433


// Edit plane for isometric view

// paper size
#define LC_PAPER_CUSTOM     0
#define LC_PAPER_A0         1
#define LC_PAPER_A1         2
#define LC_PAPER_A2         3
#define LC_PAPER_A3         4
#define LC_PAPER_A4         5
#define LC_PAPER_A5         6
#define LC_PAPER_A6         7
#define LC_PAPER_B0         11
#define LC_PAPER_B1         12
#define LC_PAPER_B2         13
#define LC_PAPER_B3         14
#define LC_PAPER_B4         15
#define LC_PAPER_B5         16
#define LC_PAPER_B6         17
#define LC_PAPER_C0         21
#define LC_PAPER_C1         22
#define LC_PAPER_C2         23
#define LC_PAPER_C3         24
#define LC_PAPER_C4         25
#define LC_PAPER_C5         26
#define LC_PAPER_C6         27
#define LC_PAPER_ANSI_A     31
#define LC_PAPER_ANSI_B     32
#define LC_PAPER_ANSI_C     33
#define LC_PAPER_ANSI_D     34
#define LC_PAPER_ANSI_E     35
#define LC_PAPER_LETTER     36
#define LC_PAPER_LEGAL      37
#define LC_PAPER_EXECUTIVE  38
#define LC_PAPER_LEDGER     39

// Printer paper orientation
#define LC_PAPER_PORTRAIT     0
#define LC_PAPER_BOOK         0
#define LC_PAPER_LANDSCAPE    1
#define LC_PAPER_ALBUM        1

// block overwrite mode
#define LC_BLOCK_OVERWRITENO   0
#define LC_BLOCK_OVERWRITEYES  1
#define LC_BLOCK_OVERWRITEDLG  2


// Litecad object types

// Non-graphical objects (Named)
#define LC_OBJ_LAYER       1  // Layer
#define LC_OBJ_LINETYPE    2  // Linetype
#define LC_OBJ_TEXTSTYLE   3  // Text style
#define LC_OBJ_DIMSTYLE    4  // Dimension style
#define LC_OBJ_BLOCK       5  // Block
#define LC_OBJ_IMAGE       6  // Image
#define LC_OBJ_VIEW        7  // View
#define LC_OBJ_MLSTYLE     8  // Multiline style

// Graphic objects
#define LC_ENT_LINE        101  // Line
#define LC_ENT_POLYLINE    102  // Polyline
#define LC_ENT_CIRCLE      103  // Circle
#define LC_ENT_ARC         104  // Arc
#define LC_ENT_BLOCKREF    105  // Block Reference  !!! do not change this value (used in CDisplay::DrawEntities)
#define LC_ENT_POINT       107  // Point
#define LC_ENT_XLINE       108  // Construction line or ray
#define LC_ENT_ELLIPSE     109  // Ellipse or elliptical arc
#define LC_ENT_TEXT        110  // Text
#define LC_ENT_TEXTWIN     111  // Text by GDI TextOut
#define LC_ENT_IMAGEREF    115  // Image Reference
#define LC_ENT_VIEWPORT    116  // Viewport
#define LC_ENT_RECT        118  // Rectangle
#define LC_ENT_ATTRIB      120  // Attribute
#define LC_ENT_ECW         121  // ECW image
#define LC_ENT_MTEXT       122  // Multiline Text
#define LC_ENT_ARCTEXT     123  // Arc Text
#define LC_ENT_HATCH       124  // Hatch
#define LC_ENT_BEZIER      125
#define LC_ENT_FACE        126  // 3D Face
#define LC_ENT_MLINE       127  // multiline polyline
#define LC_ENT_DIMROT      131  // Dimension Rotated
#define LC_ENT_DIMALI      132  // Dimension Aligned
#define LC_ENT_DIMORD      133  // Dimension Ordinate
#define LC_ENT_DIMRAD      134  // Dimension Radial
#define LC_ENT_DIMDIA      135  // Dimension Diametric
#define LC_ENT_DIMANG      136  // Dimension Angular
#define LC_ENT_LEADER      137  // Leader
#define LC_ENT_RPLAN       141  // Road plan
//#define LC_ENT_CLOTHOID    142  // Clothoid
#define LC_ENT_TIN         142  // Triangulated Irregular Network
#define LC_ENT_CUSTOM      1000
#define LC_ENT_ALL         32767   // used for bulk properties

// Lineweights
#define LC_LWEIGHT_DEFAULT  -3     // Default lineweight. Width is controlled by LC_PROP_DRW_LWDEFAULT property.
#define LC_LWEIGHT_BYBLOCK  -2     // Only for entities contained in block. Universal lineweight specified within a BlockRef entity.
#define LC_LWEIGHT_BYLAYER  -1     // Only for entities. Universal lineweight specified in the entity's layer.
#define LC_LWEIGHT_000       0     // 0.00 mm
#define LC_LWEIGHT_005       5     // 0.05 mm
#define LC_LWEIGHT_009       9     // 0.09 mm
#define LC_LWEIGHT_013       13    // 0.13 mm
#define LC_LWEIGHT_015       15    // 0.15 mm
#define LC_LWEIGHT_018       18    // 0.18 mm
#define LC_LWEIGHT_020       20    // 0.20 mm
#define LC_LWEIGHT_025       25    // 0.25 mm
#define LC_LWEIGHT_030       30    // 0.30 mm
#define LC_LWEIGHT_035       35    // 0.35 mm
#define LC_LWEIGHT_040       40    // 0.40 mm
#define LC_LWEIGHT_050       50    // 0.50 mm
#define LC_LWEIGHT_053       53    // 0.53 mm
#define LC_LWEIGHT_060       60    // 0.60 mm
#define LC_LWEIGHT_070       70    // 0.70 mm
#define LC_LWEIGHT_080       80    // 0.80 mm
#define LC_LWEIGHT_090       90    // 0.90 mm
#define LC_LWEIGHT_100       100   // 1.00 mm
#define LC_LWEIGHT_106       106   // 1.06 mm
#define LC_LWEIGHT_120       120   // 1.20 mm
#define LC_LWEIGHT_140       140   // 1.40 mm
#define LC_LWEIGHT_158       158   // 1.58 mm
#define LC_LWEIGHT_200       200   // 2.00 mm
#define LC_LWEIGHT_211       211   // 2.11 mm
#define LC_LWEIGHT_COUNT     24     // number of available values for lineweights

// variants for LC_PROP_G_COLOR property
#define LC_COLOR_RGB        0  // RGB value (COLORREF)
#define LC_COLOR_INDEX      1  // AutoCAD Color Index (ACI)

// defined ACI Colors
#define LC_COLOR_RED          1  // Red
#define LC_COLOR_YELLOW       2  // Yellow
#define LC_COLOR_GREEN        3  // Green
#define LC_COLOR_CYAN         4  // Cyan
#define LC_COLOR_BLUE         5  // Blue
#define LC_COLOR_MAGENTA      6  // Magenta
#define LC_COLOR_FOREGROUND   7  // Foreground (contrast to background color)
#define LC_COLOR_GRAY         8  // Gray
#define LC_COLOR_LTGRAY       9  // Light gray
// logical colors for entities
#define LC_COLOR_BYBLOCK      0     // entity's color by block
#define LC_COLOR_BYLAYER      256   // entity's color by layer

// text alignment types
#define LC_TA_LEFBOT          0   // Align by left bottom corner
#define LC_TA_CENBOT          1   // Align by center of bottom line
#define LC_TA_RIGBOT          2   // Align by right bottom corner
#define LC_TA_LEFCEN          3   // Align by left side of vertical center line
#define LC_TA_CENTER          4   // Align by center of text
#define LC_TA_RIGCEN          5   // Align by right side of vertical center line
#define LC_TA_LEFTOP          6   // Align by left top corner
#define LC_TA_CENTOP          7   // Align by center of top line
#define LC_TA_RIGTOP          8   // Align by right tom corner
#define LC_TA_ALIGNED         11  // Fit text between 2 points (Adjust Height)
#define LC_TA_FIT             12  // Fit text between 2 points (Adjust Width scale)

// WinAPI Text Alignment Options 
#define LC_WTA_LEFT           0
#define LC_WTA_RIGHT          2
#define LC_WTA_CENTER         6
#define LC_WTA_TOP            0
#define LC_WTA_BOTTOM         8
#define LC_WTA_BASELINE       24

// Pen Styles 
#define LC_PS_SOLID           0
#define LC_PS_DASH            1       // ------- 
#define LC_PS_DOT             2       // ....... 
#define LC_PS_DASHDOT         3       // _._._._ 
#define LC_PS_DASHDOTDOT      4       // _.._.._ 


// text flags for LC_TEXTPRM::Generation
#define LC_TEXT_BACKWARD      2 
#define LC_TEXT_UPDOWN        4

// text alignment types for arc text
#define LC_ATA_LEFT           0   // Align by left side of text
#define LC_ATA_CENTER         1   // Align by center of text
#define LC_ATA_RIGHT          2   // Align by right side of text
                          
// Polyline fit types     
#define LC_PLFIT_BULGE        0      // linear with bulges
#define LC_PLFIT_NONE         0
#define LC_PLFIT_QUAD         5      // Quadratic B-spline
#define LC_PLFIT_CUBIC        6      // Cubic B-spline
#define LC_PLFIT_SPLINE       99     // spline fitted to vertices
#define LC_PLFIT_ROUND        101    // rounded vertices
#define LC_PLFIT_LINQUAD      102    // mixed linear and quadratic segments

// Multiline justification 0 = Top; 1 = Middle; 2 = Bottom
#define LC_MLINE_TOP          0
#define LC_MLINE_MIDDLE       1
#define LC_MLINE_BOTTOM       2

// Point modes 
#define LC_POINT_PIXEL        0     // Pixel
#define LC_POINT_NONE         1     // None
#define LC_POINT_PLUS         2     // "Plus" sign through the point.
#define LC_POINT_X            3     // "X" through the point
#define LC_POINT_TICK         4     // Vertical tick mark upward from the point.
// additional elements     
#define LC_POINT_CIRCLE       32    // Circle 
#define LC_POINT_SQUARE       64    // Square
#define LC_POINT_RHOMB        128   // Rhomb
#define LC_POINT_FILLED       256   // Filled shape

// 3D Face flags
#define LC_FACE_EDGE1HIDDEN   1
#define LC_FACE_EDGE2HIDDEN   2
#define LC_FACE_EDGE3HIDDEN   4
#define LC_FACE_EDGE4HIDDEN   8

// Leader text alignment flags
#define LC_LEADER_TCENTER     0
#define LC_LEADER_TLEFT       1
#define LC_LEADER_TRIGHT      2
// Leader line attachment flags
#define LC_LEADER_VERT        1
#define LC_LEADER_CORNER      2


// keyboard type
#define LC_KBD_QWERTY  0  // QWERTY
#define LC_KBD_AZERTY  1  // AZERTY
#define LC_KBD_QWERTZ  2  // QWERTZ

// LiteCAD commands (for lcWndExeCommand)

// File I/O commands
#define LC_CMD_FILESAVE       4    // Save drawing to file. Call dialog "Save As" if filename is undefined
#define LC_CMD_FILESAVEAS     5    // Call dialog "Save File As"
#define LC_CMD_PRINT          7    // Call dialog "Print"
#define LC_CMD_RASTERIZE      8    // Call dialog "Export to raster image"

// Add entities
#define LC_CMD_POINT          201  // Draw Point
#define LC_CMD_LINE           202  // Draw Line
#define LC_CMD_XLINE          203  // Draw Construction Line
#define LC_CMD_RAY            204  // Draw Ray
#define LC_CMD_PLINE          205  // Draw Polyline
#define LC_CMD_POLYLINE       205  // Draw Polyline
#define LC_CMD_POLYGON        206  // Draw Polygon
#define LC_CMD_RECT           207  // Draw Rectangle
#define LC_CMD_CIRCLE         208  // Draw Circle
#define LC_CMD_ARC            209  // Draw Arc
#define LC_CMD_ELLIPSE        210  // Draw Ellipse
#define LC_CMD_TEXT           211  // Draw Text
#define LC_CMD_MTEXT          212  // Draw Multiline Text
#define LC_CMD_ATEXT          213  // Draw Arc Text
#define LC_CMD_INSERT         214  // Insert Block
#define LC_CMD_VPORT          215  // Insert Viewport
#define LC_CMD_BASEPOINT      216  // define block basepoint
#define LC_CMD_ATTDEF         217  // Draw Attribute Definition
#define LC_CMD_HATCH          218  // Draw Hatch
#define LC_CMD_BOUNDARY       219  // Draw boundary
#define LC_CMD_WTEXT          220  // Draw WinText
#define LC_CMD_DIMROT         231  // Draw dimension rotated
#define LC_CMD_DIMALI         232  // Draw dimension aligned
#define LC_CMD_DIMORD         233  // Draw dimension ordinate
#define LC_CMD_DIMRAD         234  // Draw dimension radius
#define LC_CMD_DIMDIA         235  // Draw dimension diameter
#define LC_CMD_DIMANG         236  // Draw dimension angular
#define LC_CMD_LEADER         237  // Draw leader
#define LC_CMD_CENTER         238  // Draw center mark
#define LC_CMD_ECW            239  // Insert ECW image
#define LC_CMD_MLINE          240  // Draw Multiline Polyline
#define LC_CMD_SPLINE         241  // Draw Spline
#define LC_CMD_RPLAN          242  // Draw Road plan
#define LC_CMD_BEZIER         243  // Draw Bezier curve
#define LC_CMD_TIN            244  // Insert TIN object
#define LC_CMD_FACE           245  // 3D face


// Edit operations
#define LC_CMD_CBCUT          301  // Cut entities to clipboard
#define LC_CMD_CBCOPY         302  // Copy entities to clipboard
#define LC_CMD_CBPASTE        303  // Paste entities from clipboard
#define LC_CMD_UNDO           304  // Undo last change
#define LC_CMD_REDO           305  // Reverse last "undo"
#define LC_CMD_COPY           306  // Copy entities
#define LC_CMD_ERASE          307  // Erase entities
#define LC_CMD_MOVE           308  // Move entities
#define LC_CMD_ROTATE         309  // Rotate entities
#define LC_CMD_SCALE          310  // Scale entities
#define LC_CMD_MIRROR         311  // Mirror entities
#define LC_CMD_EXPLODE        312  // Explode entities
#define LC_CMD_JOIN           314  // Join entities
#define LC_CMD_DEP            315  // delete extra points   // undoc
#define LC_CMD_ORDER          316  // change draw order
#define LC_CMD_CLOSEBLOCK     317  // Close Block Editor   // undoc
#define LC_CMD_TRIM           318  // Trim
#define LC_CMD_EXTEND         319  // Extend
#define LC_CMD_OFFSET         320  // Offset
#define LC_CMD_OFFSET_POINT   0 
#define LC_CMD_OFFSET_DIST    1
#define LC_CMD_BREAK          321  // Break
#define LC_CMD_STRETCH        322  // Stretch
#define LC_CMD_FILLET         323  // make fillet for 2 lines
#define LC_CMD_TINSWAPTR      332  // // undoc
#define LC_CMD_TINDELTR       333  // // undoc
#define LC_CMD_TINDELPNT      334  // // undoc
#define LC_CMD_TINPTYPES      335  // // undoc


// Display a drawing in design window
#define LC_CMD_VIEWSTART      401  //------- 1-step view commands until LC_CMD_VIEWEND
#define LC_CMD_ZOOM_IN        401  // Enlarge drawing's view
#define LC_CMD_ZOOM_OUT       402  // Diminish drawing's view
#define LC_CMD_ZOOM_EXT       403  // Zoom on drawing's extents
#define LC_CMD_ZOOM_LIM       404  // Zoom on drawing's limits
#define LC_CMD_ZOOM_PREV      405  // Display the previous view
#define LC_CMD_ZOOM_SEL       406  // Zoom on selected entities
#define LC_CMD_PAN_LEFT       407  // Shift drawing to the left
#define LC_CMD_PAN_RIGHT      408  // Shift drawing to the right
#define LC_CMD_PAN_UP         409  // Shift drawing upward
#define LC_CMD_PAN_DOWN       410  // Shift drawing downward
#define LC_CMD_VIEWEND        410  //------------------------------------------
#define LC_CMD_PAN_RT         419  // Pan realtime
#define LC_CMD_ZOOM_RT        420  // Zoom realtime
#define LC_CMD_ZOOM_WIN       421  // Zoom drawing using the Zoom rectangle (Zoom Box)
#define LC_CMD_PAGENEXT       423  // Display next layout
#define LC_CMD_PAGEPREV       424  // Display previous layout
#define LC_CMD_PAGEMODEL      425  // Display "Model Space" layout
#define LC_CMD_PAGEVPORT      426  // Display layout of active viewport (called by popup menu on AVP)
#define LC_CMD_VP_ACT         427  // activate viewport
#define LC_CMD_VP_DEACT       428  // deactivate viewport

// Format 
#define LC_CMD_LAYER          501  // Call dialog "Layers"
#define LC_CMD_LAYERNF        502  // Call dialog "Layers" without filters (with using LC_PROP_LAYER_NODLG)  // undoc
#define LC_CMD_LAYER2         502  // same as LC_CMD_LAYERNF
#define LC_CMD_COLOR          503  // Call dialog "Color"
#define LC_CMD_BCOLOR         504
#define LC_CMD_LINETYPE       505  // Call dialog "Linetypes"
#define LC_CMD_LWEIGHT        506  // Call dialog "Lineweights"
#define LC_CMD_TEXTSTYLE      507  // Call dialog "Text Styles"
#define LC_CMD_BLOCK          508  // Call dialog "Create Block"
#define LC_CMD_BLOCKS         509  // Call dialog "Blocks"
#define LC_CMD_IMAGE          510  // Call dialog "Image Manager"
#define LC_CMD_PNTSTYLE       511  // Call dialog "Point Style"
#define LC_CMD_DIMSTYLE       512  // Call dialog "Dimension Styles"
#define LC_CMD_MLSTYLE        513  // Call dialog "Multiline Styles"
#define LC_CMD_LAYOUT         514  // Call dialog "Layouts"
#define LC_CMD_LIMITS         515  // Call dialog "Limits"
#define LC_CMD_UNITS          516  // Call dialog "Drawing Units"
#define LC_CMD_DRWPRM         517  // Call dialog "Drawing's parameters"

// Miscellaneous 
#define LC_CMD_SNAP           105  // same as LC_CMD_GRID
#define LC_CMD_DAIDS          106  // Call dialog "Drafting Settings"
#define LC_CMD_GRID           107  // Call dialog "Drafting Settings / Snap and Grid"
#define LC_CMD_POLAR          108  // Call dialog "Drafting Settings / Polar tracking"
#define LC_CMD_OSNAP          109  // Call dialog "Drafting Settings / Object snap"
#define LC_CMD_OPTIONS        118  // Call dialog "Options" (Global parameters)
#define LC_CMD_PLUGIN         119  // Call dialog "Plugins"
#define LC_CMD_REGEN          120  // Regenerate drawing's views
#define LC_CMD_SELOPTS        122
#define LC_CMD_QSELECT        123
#define LC_CMD_DIST           124
#define LC_CMD_AREA           125
#define LC_CMD_SELPGON        126   // Select by polygon   // undoc
#define LC_CMD_SELCLAYER      127   // Select entities of currect layer  // undoc
#define LC_CMD_SELALL         128   // Select all entities  // undoc
#define LC_CMD_UNSELALL       129   // Unselect all entities  // undoc
#define LC_CMD_PURGE          130   // Clears a drawing database from "deleted" objects

#define LC_CMD_HELP           1001  // Display Context Help
#define LC_CMD_REPEAT         1002  // Repeat last command
#define LC_CMD_RESET          1003  // Cancel currently active command, de-select all entities, redraw drawing

#define LC_CMD_SW_GRID        1011  // Toggles "Show coordinate grid" mode
#define LC_CMD_SW_GRIDSNAP    1012  // Toggles "Snap to coordinate grid" mode
#define LC_CMD_SW_LWEIGHT     1013  // Toggles "Display lineweights" mode
#define LC_CMD_SW_OSNAP       1014  // Toggles "Object Snap" mode
#define LC_CMD_SW_POLAR       1015  // Toggles "Polar tracking" mode
#define LC_CMD_SW_ORTHO       1016  // Toggles "Ortho" mode

// snap commands
#define LC_CMD_SNAP_NONE      1100
#define LC_CMD_SNAP_NODE      1101
#define LC_CMD_SNAP_ENDPOINT  1102
#define LC_CMD_SNAP_MIDPOINT  1103
#define LC_CMD_SNAP_CENTER    1104
#define LC_CMD_SNAP_QUADRANT  1105
#define LC_CMD_SNAP_NEAREST   1106
#define LC_CMD_SNAP_INTER     1107
#define LC_CMD_SNAP_PERPEND   1108
#define LC_CMD_SNAP_TANGENT   1109
#define LC_CMD_SNAP_INSERT    1110
#define LC_CMD_SNAP_DIALOG    1111

#define LC_CMD_CUSTOM         30000


// Snap modes
#define LC_SNAP_NULL          0      //0x00000 no snap at all
#define LC_SNAP_NODE          1      //0x00001 to a Point object, dimension definition point, or dimension text origin.
#define LC_SNAP_ENDPOINT      2      //0x00002 to the closest endpoint of an Arc, Elliptical Arc, Line, Multiline, Polyline segment, Ray
#define LC_SNAP_MIDPOINT      4      //0x00004 to the midpoint of an arc, ellipse, elliptical arc, line, multiline, polyline segment, region, solid, spline, or xline.
#define LC_SNAP_CENTER        8      //0x00008 to the center of an arc, circle, ellipse, or elliptical arc.
#define LC_SNAP_NEAREST       16     //0x00010 to the nearest point on an arc, circle, ellipse, elliptical arc, line, multiline, point, polyline, ray, spline, or xline.
#define LC_SNAP_INTER         32     //0x00020 to the intersection of an arc, circle, ellipse, elliptical arc, line, multiline, polyline, ray, region, spline, or xline.
#define LC_SNAP_PERPEND       64     //0x00040 to a point perpendicular to an arc, circle, ellipse, elliptical arc, line, multiline, polyline, ray, region, solid, spline, or xline
#define LC_SNAP_TANGENT       128    //0x00080 to the tangent of an arc, circle, ellipse, elliptical arc, or spline.
#define LC_SNAP_QUADRANT      256    //0x00100 to a quadrant point of an arc, circle, ellipse, or elliptical arc.
#define LC_SNAP_INSERT        512    //0x00200 to the insertion point of an attribute, a block, a shape, or text.
#define LC_SNAP_NONE          1024   //0x00400 temporary disable snap
#define LC_SNAP_ALL           1023   //0x003FF all modes
//#define LC_SNAP_DBLTANG       65536  //0x10000 double tangent


// ID of help file topic
#define LC_HELP_DG_LIMITS       1
#define LC_HELP_DG_GRID         2
#define LC_HELP_DG_PSNAP        3
#define LC_HELP_DG_OSNAP        4
#define LC_HELP_DG_OSNAP2       5
#define LC_HELP_DG_OPTIONS      6
#define LC_HELP_DG_INPUTCOORD   7
#define LC_HELP_DG_LAYERS       8
#define LC_HELP_DG_LAYSTATES    9
#define LC_HELP_DG_TEXTSTYLES   10
#define LC_HELP_DG_PNTSTYLE     11
#define LC_HELP_DG_SELFONT      13
#define LC_HELP_DG_LINETYPES    14
#define LC_HELP_DG_LOADLINETYPE 15
#define LC_HELP_DG_SELLTYPE     16
#define LC_HELP_DG_COLOR        17
#define LC_HELP_DG_TEXT         18
#define LC_HELP_DG_LINEWEIGHT   19
#define LC_HELP_DG_IMAGES       20
#define LC_HELP_DG_IMAGEINSERT  21
#define LC_HELP_DG_BLOCKS       22
#define LC_HELP_DG_INSERT       23
#define LC_HELP_DG_PRINT        24
#define LC_HELP_DG_RASTER       25
#define LC_HELP_DG_LAYOUTS      26
#define LC_HELP_DG_PAGEPROP     27
#define LC_HELP_DG_CREBLOCK     28
#define LC_HELP_DG_SELBLOCK     29
#define LC_HELP_DG_SELTSTYLE    30
#define LC_HELP_DG_ATEXT        31
#define LC_HELP_DG_FONTREPLACE  32
#define LC_HELP_DG_ATTDEF       33
#define LC_HELP_DG_HATCH        34
#define LC_HELP_DG_DRWPROPS     35
#define LC_HELP_DG_UNITS        36
#define LC_HELP_DG_MLSTYLES     37


// Attribute flags
#define LC_ATTRIB_HIDDEN      1
#define LC_ATTRIB_CONST       2
#define LC_ATTRIB_VERIFY      4
#define LC_ATTRIB_PRESET      8
#define LC_ATTRIB_LOCK        16
#define LC_ATTRIB_MTEXT       32

// 3D Face flags (must be the same as in "..\odt\ad2.h"
#define LC_FACE_EDGE1INVIS     1
#define LC_FACE_EDGE2INVIS     2
#define LC_FACE_EDGE3INVIS     4
#define LC_FACE_EDGE4INVIS     8

// decimal separator types
#define LC_DECSEP_POINT       0
#define LC_DECSEP_COMMA       1
#define LC_DECSEP_NONE        2
                            
// arrowhead types          
#define LC_ARROW_CLOSEDF      0    // Closed filled
#define LC_ARROW_CLOSEDB      1    // Closed blank
#define LC_ARROW_CLOSED       2    // Closed
#define LC_ARROW_DOT          3    // Dot
#define LC_ARROW_ARCHTICK     4    // Architectural tick
#define LC_ARROW_OBLIQUE      5    // Oblique
#define LC_ARROW_OPEN         6    // Open
#define LC_ARROW_ORIGIN       7    // Origin indicator
#define LC_ARROW_ORIGIN2      8    // Origin indicator 2
#define LC_ARROW_OPEN90       9    // Right angle
#define LC_ARROW_OPEN30       10   // Open 30
#define LC_ARROW_DOTSMALL     11   // Dot small
#define LC_ARROW_DOTB         12   // Dot blank
#define LC_ARROW_DOTSMALLB    13   // Dot small blank
#define LC_ARROW_BOX          14   // Box
#define LC_ARROW_BOXF         15   // Box filled
#define LC_ARROW_DATUM        16   // Datum triangle
#define LC_ARROW_DATUMF       17   // Datum triangle filled
#define LC_ARROW_INTEGRAL     18   // Integral
#define LC_ARROW_NONE         19   // None

// Plugin Interface Types
// Do not change this values, because it must be the same in plugin DLLs
#define LC_PLUG_IMPDRW        2   // load a drawing from a file into LiteCAD database (in memory)
#define LC_PLUG_EXPDRW        3   // save a drawing from LiteCAD database into a file
#define LC_PLUG_IMGDIB        4   // load an image from a file into LiteCAD DIB

// values for the F_FIOPROGRESS Mode
#define LC_FP_FLOAD           0   // szFileName - a file is being loaded
#define LC_FP_FSAVE           1   // szFileName - a file is being saved
#define LC_FP_NITEMS          2   // IntVal - number of items
#define LC_FP_ITEM            3  

// Mode values for lcGetFileName()
#define LC_DG_SELFILE         0   // dialog "Select File"
#define LC_DG_RECENT          1   // dialog "Recent"
#define LC_DG_TEMPLATE        2   // dialog "Select Template"

// Error code
#define LC_ERR_USERCANCEL     1   // user cancelled operation
#define LC_ERR_OBJTYPE        2   // wrong type of object
#define LC_ERR_FILENAME       3   // wrong filename
#define LC_ERR_FILELOAD       4
#define LC_ERR_FILESAVE       5
#define LC_ERR_NOTAG          6   // string tag is not found
#define LC_ERR_UNRESBLOCKREF  7   // unresolved block reference
#define LC_ERR_UNRESVIEWREF   8   // unresolved view reference
#define LC_ERR_UNRESHATCH     9   // unresolved hatch 
#define LC_ERR_SELBLOCKM      10  // Model space block for paper view
#define LC_ERR_SELBLOCKP      11  // Paper space block for model view

#define LC_MAX_USERPNT        100  // lcWndGetPoint and lcWndGetPointBuf


//-----------------------------------------------
//  Objects Properties
//-----------------------------------------------

// Global properties
#define LC_PROP_G_REGCODE           1      //  W string; registration code
#define LC_PROP_G_VERSION           2      // R  string; Litecad version
#define LC_PROP_G_INSTALLED         3      // R  bool; TRUE if LiteCAD is installed in this system

#define LC_PROP_G_DIRDLL            11     // R  string; directory of Litecad.dll
#define LC_PROP_G_DIRDATA           12     // RW string; litecad data directory
#define LC_PROP_G_DIRFONTS          13     // R  string; directory of data\Fonts
#define LC_PROP_G_DIRLNG            14     // R  string; directory of data\Languages
#define LC_PROP_G_DIRPLUG           15     // R  string; directory of data\PlugIns
#define LC_PROP_G_DIRTPL            16     // R  string; directory of data\Templates
#define LC_PROP_G_DIRCFG            17     // RW  string; directory of Litecad config files
#define LC_PROP_G_SAVECFG           18     // RW bool; defines if save config or not
#define LC_PROP_G_TEMPLATE          19     // RW string; default template file for new drawings
#define LC_PROP_G_FILEHATCH         20     // RW string; hatch patterns file
#define LC_PROP_G_FILELTYPE         21     // RW string; linetype file
#define LC_PROP_G_DLGRECENT         22     // RW bool; Display dialog "Recent Files" at startup
#define LC_PROP_G_ADDRECENT         23     // RW bool; defines if lcDrwLoad will add a filename into recent files list

#define LC_PROP_G_CURSORARROW       31     //    same as LC_PROP_G_CURSORARROW
#define LC_PROP_G_CURSORSYS         31     // RW bool|int|handle; Enable arrow cursor | set cursor
#define LC_PROP_G_CURSORCROSS       32     // RW bool; Enable crosshair cursor
#define LC_PROP_G_CURSORSIZE        33     // RW int; Size of crosshair cursor
#define LC_PROP_G_CURSORPROMPT      34     // RW int; >0 Enable command prompt near cursor, 2-hide command name

#define LC_PROP_G_AUTOSELECT        41     // RW bool; Auto select by point
#define LC_PROP_G_AUTOUNSELECT      42     // RW bool; Determines state of selected entities after edit command was executed
#define LC_PROP_G_PICKFIRST         43     // RW bool; Controls whether you select objects before (noun-verb selection) or after you issue a command
#define LC_PROP_G_PICKAUTO          44     // RW bool; Controls automatic windowing at the Select Objects prompt
#define LC_PROP_G_PICKDRAG          45     // RW bool; Controls the method of drawing a selection window
#define LC_PROP_G_PICKADD           46     // RW bool; Controls whether subsequent selections replace the current selection set or add to it
#define LC_PROP_G_PICKBOXSIZE       47     // RW int; Half-size of selecting square, in pixels
#define LC_PROP_G_SELBYLAYER        48     // RW bool; Allows selection only on current layer
#define LC_PROP_G_SELINSIDE         49     // RW bool; Allows selection by click on inner area of closed and filled objects
#define LC_PROP_G_SELCOLOR          50     // RW int; Color of selected objects (COLORREF)
#define LC_PROP_G_DRAGCOLOR         51     // RW int; Color of dragged objects (COLORREF)

#define LC_PROP_G_ENABLEGRIPS       61     // RW bool; Grips visibility when user selects an entities
#define LC_PROP_G_GRIPSIZE          62     // RW int; Size of grip square, in pixels
#define LC_PROP_G_GRIPCOLOR         63     // RW int; Grips color (COLORREF)
#define LC_PROP_G_GRIPSLIMIT        64     // RW int; Max number of entities to display grips
#define LC_PROP_G_MARKVERTEX        65     // RW int; vertex grip: draw index and mark current vertex 

#define LC_PROP_G_PANSTEP           71     // RW int; Minimal step, pixels
#define LC_PROP_G_PANFILLING        72     // RW bool; Display polygon filling
#define LC_PROP_G_PANHATCH          73     // RW bool; Display hatch pattern
#define LC_PROP_G_PANPLWIDTH        74     // RW bool; Display polyline width
#define LC_PROP_G_PANLWEIGHT        75     // RW bool; Display lineweight
#define LC_PROP_G_PANFILLCHAR       76     // RW bool; Display text char filling
#define LC_PROP_G_PANRECTCHAR       77     // RW int; Draw text char as rect below the size, pixel
#define LC_PROP_G_PANLOWRES         78     // RW bool; lower resolution at pan mode

#define LC_PROP_G_CHARBOXSIZE       81     // RW int; if char's height is smaller, then it is drawn as a rect
#define LC_PROP_G_CHARFILLSIZE      82     // RW int; if char's height is bigger, then a filling is available
#define LC_PROP_G_CHARQUALITY       83     // RW int; Number of lines per TTF char's curve segment
#define LC_PROP_G_CURVEQUALITY      84     // RW int; num of linear segments for one curve segment of polyline
#define LC_PROP_G_SHOWPIXENT        85     // RW bool; TRUE - Display small entities as pixel, FALSE - don't display

#define LC_PROP_G_OSNAPMAGNET       91     // RW bool; magnet for cursor
#define LC_PROP_G_OSNAPMARK         92     // RW bool; display osnap marker
#define LC_PROP_G_OSNAPAPER         93     // RW bool; display osnap aperture box
#define LC_PROP_G_OSNAPMBMENU       94     // RW bool; osnap menu on middle button (+Shift - pan window)
#define LC_PROP_G_OSNAPMARKSIZE     95     // RW int; half-size of marker indicating snap point, pixels
#define LC_PROP_G_OSNAPAPERSIZE     96     // RW int; half-size of square around cursor, used for snap, pixels
#define LC_PROP_G_OSNAPMARKCOLOR    97     // RW int; osnap marker color (COLORREF)

#define LC_PROP_G_CMDFONT           101    // RW string; font for command window
#define LC_PROP_G_CMDFONTSIZE       102    // RW int; font size for command window

#define LC_PROP_G_GETDELENT         111    // RW bool; controls if lcBlockGetEnt... function will retrieve deleted entities or not
#define LC_PROP_G_ANGSEPDMS         112    // RW string; code of separator symbol for "Deg,Min,Sec" angle units
#define LC_PROP_G_ICON16            113    // RW string|handle|int; replaces icon for dialogs
#define LC_PROP_G_ICON32            114    // RW string|handle|int; replaces icon for dialogs
#define LC_PROP_G_PRINTINCH         115    // RW bool; units for "Print" dialog
#define LC_PROP_G_REDEFLNGTAGS      116    // RW bool; to use with lcStrFileLoad
#define LC_PROP_G_EXPLODEARC        117    // RW bool; enables exploding of arcs and circles

#define LC_PROP_G_WNDSTYLE          131    // RW int; Litecad window style (used when OCX object is created)  // undoc
#define LC_PROP_G_INITCOUNT         132    // R  int;  // undoc
#define LC_PROP_G_CLOTPREC          133    // RW int; precision to calculate clothoid (RPLAN) 0-2   // undoc
#define LC_PROP_G_JUR               134    // RW bool;   // undoc
#define LC_PROP_G_NOLCD             135    // RW bool;   // undoc
#define LC_PROP_G_NAME              136    // RW string; DLL_NAME  // undoc

#define LC_PROP_LNG_TAG             251    // R  string;   // undoc  // works with lcStrSet( L"", L"*F" ); lcStrSet( L"", L"*N" )
#define LC_PROP_LNG_STR             252    // R  string;   // undoc
#define LC_PROP_LNG_STR0            253    // R  string;   // undoc
#define LC_PROP_LNG_OLD             254    //  W bool; let lcStrFileSave to load old LNG format  // undoc
#define LC_PROP_LNG_DEFAULT         255    // RW string; default language name (if "default.lng" is absent)  // undoc


#define LC_PROP_FONT__MIN           281  
#define LC_PROP_FONT_FILENAME       281    // R  string;      // undoc
#define LC_PROP_FONT_NAME           282    // R  string;  // undoc
#define LC_PROP_FONT_HEIGHT         283    // R  float;  // undoc
#define LC_PROP_FONT_FILLED         284    // R  bool;  // undoc
#define LC_PROP_FONT_TTF            285    // R  bool;  // undoc
#define LC_PROP_FONT_NCHARS         286    // R  int; number of chars in a font  // undoc
#define LC_PROP_FONT_CHARCODE       287    // RW int; char code for LC_PROP_FONT_CHAR  // undoc
#define LC_PROP_FONT_CHAR           288    // R  handle; Pointer to CGeSymbol object  // undoc
#define LC_PROP_FONT__MAX           299

// Design window
#define LC_PROP_WND__MIN            301
#define LC_PROP_WND_ID              301    // RW int; identifier
#define LC_PROP_WND_VIEW            302    // R  handle; Handle to active view
#define LC_PROP_WND_VIEWBLOCK       303    // R  handle; Handle to active block
#define LC_PROP_WND_VIEWDRW         304    // R  handle; Handle to active drawing
#define LC_PROP_WND_WIDTH           306    // R  int; Window's width (pixels)
#define LC_PROP_WND_HEIGHT          307    // R  int; Window's height (pixels)
#define LC_PROP_WND_HWND            308    // R  handle; WinAPI handle (HWND)
#define LC_PROP_WND_FOCUS           309    // R  bool; Indication "Has focus"
#define LC_PROP_WND_EMPTYTEXT       310    // RW string; Text displayed when window have not a drawing
#define LC_PROP_WND_CURSORX         311    // R  int|float; Cursor position X (pixels)|Cursor position X (drawing's units)
#define LC_PROP_WND_CURX            311    // R  int|float; Cursor position X (pixels)|Cursor position X (drawing's units)
#define LC_PROP_WND_CURSORY         312    // R  int|float; Cursor position Y (pixels)|Cursor position Y (drawing's units)
#define LC_PROP_WND_CURY            312    // R  int|float; Cursor position Y (pixels)|Cursor position Y (drawing's units)
#define LC_PROP_WND_HASBASE         314    // R  bool; Has base point    // undoc
#define LC_PROP_WND_BASEX           315    // R  float; Base point position X   // undoc
#define LC_PROP_WND_BASEY           316    // R  float; Base point position Y   // undoc
#define LC_PROP_WND_BASEDIST        318    // R  float; Distance from Base point to Cursor   // undoc
#define LC_PROP_WND_BASEANGLE       319    // R  float|string; Angle from Base point to Cursor   // undoc
#define LC_PROP_WND_HOCX            321    // RW handle; OCX control which own this window
#define LC_PROP_WND_DRAWPICKBOX     322    // RW bool;   // undoc
#define LC_PROP_WND_COMMAND         323    // R  int; Id of active command
#define LC_PROP_WND_PIXELSIZE       324    // R  float; Current scale of the drawing in the window, units per pixel
#define LC_PROP_WND_PICKBOXSIZE     325    // R  float; Half-size of selecting square, in drawing units
#define LC_PROP_WND_CURLEF          326    // R  float; left side of selecting square, in drawing units
#define LC_PROP_WND_CURBOT          327    // R  float; bottom side of selecting square, in drawing units
#define LC_PROP_WND_CURRIG          328    // R  float; right side of selecting square, in drawing units
#define LC_PROP_WND_CURTOP          329    // R  float; top side of selecting square, in drawing units
#define LC_PROP_WND__MAX            399

// Drawing
#define LC_PROP_DRW__MIN            401
#define LC_PROP_DRW_GUID            401    // R  string; Drawing's Globally Unique Identifier
#define LC_PROP_DRW_FILENAME        402    // RW string; Drawing's filename
#define LC_PROP_DRW_READONLY        403    // RW bool; "Readonly" flag
#define LC_PROP_DRW_BLOCKX          404    // RW float; basepoint X of active block
#define LC_PROP_DRW_BLOCKY          405    // RW float; basepoint Y of active block
#define LC_PROP_DRW_BLOCKZ          406    // RW float; basepoint Z of active block

#define LC_PROP_DRW_COLORBACKM      414    // RW int; background color for Model Space
#define LC_PROP_DRW_COLORBACKP      415    // RW int; background color for Paper Space
#define LC_PROP_DRW_COLORFOREM      416    // RW int; foreground color on Model Space
#define LC_PROP_DRW_COLORFOREP      417    // RW int; foreground color on Paper Space
#define LC_PROP_DRW_COLORCURSORM    418    // RW int; cursor color on Model Space
#define LC_PROP_DRW_COLORCURSORP    419    // RW int; cursor color on Paper Space
#define LC_PROP_DRW_COLORPAPER      420    // RW int; color of paper sheet on Paper Space
#define LC_PROP_DRW_COLORPAPER2     421    // RW int; color of paper sheet shadow on Paper Space
#define LC_PROP_DRW_LUNITS          422    // RW int; Units format for coordinates and distances (LC_LUNIT_SCIEN and others)
#define LC_PROP_DRW_LUPREC          423    // RW int; Units precision for coordinates and distances (0..8)
#define LC_PROP_DRW_INSUNITS        424    // RW int; Units to scale inserted content (LC_INSUNIT_MILLIMETERS and others)
#define LC_PROP_DRW_AUNITS          425    // RW int; Angle units (LC_AUNIT_DEGREE and others)
#define LC_PROP_DRW_AUPREC          426    // RW int; number of decimal digits (0..8)
#define LC_PROP_DRW_ANGBASE         427    // RW float; Base angle
#define LC_PROP_DRW_ANGDIR          428    // RW int|bool; angle direction, 0-counterclockwise, 1-clockwise
#define LC_PROP_DRW_PDMODE          429    // RW int; Point mode (LC_POINT_PIXEL and others)
#define LC_PROP_DRW_PDSIZE          430    // RW float; Point size
#define LC_PROP_DRW_LTSCALE         431    // RW float; Linetype scale
#define LC_PROP_DRW_LWEIGHT         432    // RW int; Lineweight
#define LC_PROP_DRW_LWDEFAULT       433    // RW int; Default lineweight
#define LC_PROP_DRW_LWSCALE         434    // RW int; Scale to display lineweights
#define LC_PROP_DRW_LWDISPLAY       435    // RW bool; "Display lineweights" flag
#define LC_PROP_DRW_SYNCZOOM        436    // RW bool; "Synchronize Layouts zoom" flag 
#define LC_PROP_DRW_CMLJUST         437    // RW int; Current multiline justification LC_MLINE_TOP and others
#define LC_PROP_DRW_CMLSCALE        438    // RW float; Current multiline scale

#define LC_PROP_DRW_COLOR           501    // RW string; Active color
#define LC_PROP_DRW_BCOLOR          502    // RW string; Active border color
#define LC_PROP_DRW_COLORBYLAYER    503    // RW bool; Color "ByLayer"
#define LC_PROP_DRW_COLORBYBLOCK    504    // RW bool; Color "ByBlock"
#define LC_PROP_DRW_BCOLORBYLAYER   505    // RW bool; Border Color "ByLayer"
#define LC_PROP_DRW_BCOLORBYBLOCK   506    // RW bool; Border Color "ByBlock"
#define LC_PROP_DRW_COLORI          507    // RW int; R bool; Active Color Index
#define LC_PROP_DRW_COLORT          508    // RW int; R bool; Active True Color
#define LC_PROP_DRW_BCOLORI         509    // RW int; R bool; Active Border Color Index
#define LC_PROP_DRW_BCOLORT         510    // RW int; R bool; Active Border True Color

#define LC_PROP_DRW_LAYER           511    // RW handle|string; Handle to active layer|Name of active layer
#define LC_PROP_DRW_LINETYPE        512    // RW handle|string; Handle to active linetype|Name of active linetype
#define LC_PROP_DRW_TEXTSTYLE       514    // RW handle|string; Handle to active text style|Name of active text style
#define LC_PROP_DRW_DIMSTYLE        515    // RW handle|string; Handle to active dim style|Name of active dim style
#define LC_PROP_DRW_MLSTYLE         516    // RW handle|string; Handle to active mline style|Name of active mline style
#define LC_PROP_DRW_VIEW            517    // RW handle|string; Handle to active view|Name of active view
#define LC_PROP_DRW_BLOCK           518    // RW handle|string; Handle to active block|Name of active block

#define LC_PROP_DRW_LAYER_0         531    // R  handle; Handle to layer "0"
#define LC_PROP_DRW_LINETYPE_CONT   532    // R  handle; Handle to linetype "Continuous"
#define LC_PROP_DRW_LINETYPE_BYLAY  533    // R  handle; Handle to linetype "ByLayer"
#define LC_PROP_DRW_LINETYPE_BYBLK  534    // R  handle; Handle to linetype "ByBlock"
#define LC_PROP_DRW_TEXTSTYLE_STD   535    // R  handle; Handle to text style "Standard"
#define LC_PROP_DRW_TSTYLE_STD      535    // R  handle; Handle to text style "Standard"
#define LC_PROP_DRW_DIMSTYLE_STD    536    // R  handle; Handle to dim style "Standard"
#define LC_PROP_DRW_MLSTYLE_STD     537    // R  handle; Handle to mline style "Standard"
#define LC_PROP_DRW_VIEW_MODEL      538    // R  handle; Handle to view "Model"
#define LC_PROP_DRW_BLOCK_MODEL     539    // R  handle; Handle to "*Model_Space" block

#define LC_PROP_DRW_IDMAX           558    // R  int64|string; max Unique Identifier  // undoc
#define LC_PROP_DRW_DESCR           559    // RW string; drawing's description  
#define LC_PROP_DRW_COMMENT         559    // RW string; drawing's description  
#define LC_PROP_DRW_INT0            560    // RW int;   
#define LC_PROP_DRW_INT1            561    // RW int;   
#define LC_PROP_DRW_INT2            562    // RW int;   
#define LC_PROP_DRW_INT3            563    // RW int;   
#define LC_PROP_DRW_INT4            564    // RW int;   
#define LC_PROP_DRW_INT5            565    // RW int;   
#define LC_PROP_DRW_INT6            566    // RW int;   
#define LC_PROP_DRW_INT7            567    // RW int;   
#define LC_PROP_DRW_INT8            568    // RW int;   
#define LC_PROP_DRW_INT9            569    // RW int;   
#define LC_PROP_DRW_FLOAT0          570    // RW float; 
#define LC_PROP_DRW_FLOAT1          571    // RW float; 
#define LC_PROP_DRW_FLOAT2          572    // RW float; 
#define LC_PROP_DRW_FLOAT3          573    // RW float; 
#define LC_PROP_DRW_FLOAT4          574    // RW float; 
#define LC_PROP_DRW_FLOAT5          575    // RW float; 
#define LC_PROP_DRW_FLOAT6          576    // RW float; 
#define LC_PROP_DRW_FLOAT7          577    // RW float; 
#define LC_PROP_DRW_FLOAT8          578    // RW float; 
#define LC_PROP_DRW_FLOAT9          579    // RW float; 
#define LC_PROP_DRW_STR0            580    // RW string;
#define LC_PROP_DRW_STR1            581    // RW string;
#define LC_PROP_DRW_STR2            582    // RW string;
#define LC_PROP_DRW_STR3            583    // RW string;
#define LC_PROP_DRW_STR4            584    // RW string;
#define LC_PROP_DRW_STR5            585    // RW string;
#define LC_PROP_DRW_STR6            586    // RW string;
#define LC_PROP_DRW_STR7            587    // RW string;
#define LC_PROP_DRW_STR8            588    // RW string;
#define LC_PROP_DRW_STR9            589    // RW string;
#define LC_PROP_DRW_XDATASIZE       590    // RW int; size of extra data (bytes)     
#define LC_PROP_DRW_XDATA           591    // RW handle; pointer to extra data       
#define LC_PROP_DRW_HOCX            598    // RW handle; OCX control which own this drawing
#define LC_PROP_DRW_DIRTY           599    // RW bool; "Drawing was modified" flag
#define LC_PROP_DRW__MAX            599

#define LC_PROP_TABLE__MIN          1000 

// Common properties for tables
#define LC_PROP_TABLE_ID            1001  // R  int64|string; Unique Identifier
#define LC_PROP_TABLE_NAME          1002  // R  string; Table name      
#define LC_PROP_TABLE_DESC          1003  // RW string; Description     
#define LC_PROP_TABLE_DESCR         1003  // RW string; Description     
#define LC_PROP_TABLE_DRW           1004  // R  handle; Handler to owner drawing 
#define LC_PROP_TABLE_DELETED       1005  // R  bool; "Deleted" flag    
#define LC_PROP_TABLE_ODHANDLE      1010  // RW string; used to save DWGdirect handle  // undoc
#define LC_PROP_TABLE_TYPE          1011  // R  int; object type (LC_OBJ_LAYER and others)    
#define LC_PROP_TABLE_PRIORITY      1012  // RW int; priority for sorting   
#define LC_PROP_TABLE_XDATASIZE     1013  // RW int; size of extra data (bytes)
#define LC_PROP_TABLE_XDATA         1014  // RW handle; pointer to extra data  
#define LC_PROP_TABLE_XSTR          1015  // RW string; user string (uses XDATA buffer) 
#define LC_PROP_TABLE_INT0          1016  // RW int; user value  
#define LC_PROP_TABLE_INT1          1017  // RW int; user value  
#define LC_PROP_TABLE_INT2          1018  // RW int; user value  
#define LC_PROP_TABLE_INT3          1019  // RW int; user value  
#define LC_PROP_TABLE_INT4          1020  // RW int; user value  
#define LC_PROP_TABLE_FLOAT0        1021  // RW float; user value
#define LC_PROP_TABLE_FLOAT1        1022  // RW float; user value
#define LC_PROP_TABLE_FLOAT2        1023  // RW float; user value
#define LC_PROP_TABLE_FLOAT3        1024  // RW float; user value
#define LC_PROP_TABLE_FLOAT4        1025  // RW float; user value
#define LC_PROP_TABLE_NREFS         1099  // R  int; number of references to a table
#define LC_PROP_TABLEBASE__MAX      1100

// Layer
#define LC_PROP_LAYER__MIN          1101 
#define LC_PROP_LAYER_ID            1001  // R  int64|string; Unique Identifier
#define LC_PROP_LAYER_NAME          1002  // RW string; Layer Name
#define LC_PROP_LAYER_DESC          1003  // RW string; Description
#define LC_PROP_LAYER_DESCR         1003  // RW string; Description
#define LC_PROP_LAYER_DRW           1004  // R  handle; Handle to owner drawing~
#define LC_PROP_LAYER_DELETED       1005  // R  bool; "Deleted" flag
#define LC_PROP_LAYER_COLOR         1125  // RW string; Color
#define LC_PROP_LAYER_BCOLOR        1126  // RW string; Border Color  
#define LC_PROP_LAYER_COLORI        1127  // RW int; R bool; Color Index
#define LC_PROP_LAYER_COLORT        1128  // RW int; R bool; True Color
#define LC_PROP_LAYER_BCOLORI       1129  // RW int; R bool; Border Color Index
#define LC_PROP_LAYER_BCOLORT       1130  // RW int; R bool; Border True Color
#define LC_PROP_LAYER_LINETYPE      1131  // RW handle|string; Handle to Linetype|Name of Linetype
#define LC_PROP_LAYER_LWEIGHT       1132  // RW int; Lineweight
#define LC_PROP_LAYER_LOCKED        1133  // RW bool; "No edit" flag
#define LC_PROP_LAYER_NOPRINT       1134  // RW bool; "Not printed" flag
#define LC_PROP_LAYER_VISIBLE       1135  // RW bool; "Visible"; flag
#define LC_PROP_LAYER_0             1136  // R  bool; "Layer 0" flag
#define LC_PROP_LAYER_NODLG         1138  // RW bool; not displayed in the "Layers" dialog   // undoc
#define LC_PROP_LAYER__MAX          1140

// Linetype
#define LC_PROP_LINETYPE__MIN       1141 
#define LC_PROP_LINETYPE_ID         1001  // R  int64|string; Unique Identifier
#define LC_PROP_LINETYPE_NAME       1002  // RW string; Linetype Name
#define LC_PROP_LINETYPE_DESC       1003  // RW string; Description
#define LC_PROP_LINETYPE_DESCR      1003  // RW string; Description
#define LC_PROP_LINETYPE_DRW        1004  // R  handle; Handle to owner drawing~
#define LC_PROP_LINETYPE_DELETED    1005  // R  bool; "Deleted" flag
#define LC_PROP_LINETYPE_DATA       1145  // RW string; Linetype data in text form
#define LC_PROP_LINETYPE_SCALE      1146  // RW float; Global scale for this linetype
#define LC_PROP_LINETYPE_CONTINUOUS 1147  // R  bool; "Continuous" flag
#define LC_PROP_LINETYPE_BYLAYER    1148  // R  bool; "By Layer" flag
#define LC_PROP_LINETYPE_BYBLOCK    1149  // R  bool; "By Block" flag
#define LC_PROP_LINETYPE_STD        1150  // R  bool; standard linetype ("Continuous" or "By Layer" or "By Block")     // undoc
#define LC_PROP_LINETYPE_PATLEN     1151  // R  float; Pattern length
#define LC_PROP_LINETYPE_NELEM      1153  // R  int; number of elements
#define LC_PROP_LINETYPE_IELEM      1154  //  W int; set index of active element
#define LC_PROP_LTELEM_LEN          1155  // R  float; segment length
#define LC_PROP_LTELEM_COMPLEX      1156  // R  bool; TRUE - element contains shape or text
#define LC_PROP_LTELEM_SHAPE        1157  // R  bool; TRUE - text style is used, FALSE - draw only szText[0] and fontfile is used
#define LC_PROP_LTELEM_TEXT         1158  // R  string; Text
#define LC_PROP_LTELEM_STYLE        1159  // R  handle; text style (valid if LC_PROP_LTELEM_SHAPE is FALSE)
#define LC_PROP_LTELEM_FONTNAME     1160  // R  string; fontname (valid if LC_PROP_LTELEM_SHAPE is TRUE)
#define LC_PROP_LTELEM_SCALE        1161  // R  float; shape scale
#define LC_PROP_LTELEM_ANGLE        1162  // R  float; rotation angle in radians for a text element in the linetype
#define LC_PROP_LTELEM_ABSANGLE     1163  // R  bool; if TRUE - RotAngle is absolute 
#define LC_PROP_LTELEM_X            1164  // R  float; x offset of a shape
#define LC_PROP_LTELEM_Y            1165  // R  float; y offset of a shape
#define LC_PROP_LINETYPE__MAX       1170

// Text style
#define LC_PROP_TSTYLE__MIN         1171
#define LC_PROP_TSTYLE_ID           1001  // R  int64|string; Unique Identifier
#define LC_PROP_TSTYLE_NAME         1002  // RW string; Style Name
#define LC_PROP_TSTYLE_DESC         1003  // RW string; Description
#define LC_PROP_TSTYLE_DESCR        1003  // RW string; Description
#define LC_PROP_TSTYLE_DRW          1004  // R  handle; Handle to owner drawing
#define LC_PROP_TSTYLE_DELETED      1005  // R  bool; "Deleted" flag
#define LC_PROP_TSTYLE_FONT         1175  // RW string; Font filename
#define LC_PROP_TSTYLE_HFONT        1176  // R  handle; Handle to font
#define LC_PROP_TSTYLE_HEIGHT       1177  // RW float; Default height
#define LC_PROP_TSTYLE_WSCALE       1178  // RW float; Default width scale
#define LC_PROP_TSTYLE_OBLIQUE      1179  // RW float; Default obluque angle
#define LC_PROP_TSTYLE_ANGLE        1180  // RW float; Default rotation angle
#define LC_PROP_TSTYLE_ALIGN        1181  // RW int; Default alignment
#define LC_PROP_TSTYLE_UPDOWN       1182  // RW bool; "Upside down" flag
#define LC_PROP_TSTYLE_BACKWARD     1183  // RW bool; "Backward" flag
#define LC_PROP_TSTYLE_LINESPACE    1184  // RW float; Default linespace
#define LC_PROP_TSTYLE_CHARSPACE    1185  // RW float; Default charspace
#define LC_PROP_TSTYLE_STANDARD     1186  // R  bool; "Standard" flag
#define LC_PROP_TSTYLE_SHAPES       1187  // R  bool; "Shapes" flag
//#define LC_PROP_TSTYLE_LCFONT       10  // R  bool; if TRUE - Litecad LCF font is used
#define LC_PROP_TSTYLE_WINFONT      1188  // R  bool; if TRUE - Windows True Type font is used
#define LC_PROP_TSTYLE_BOLD         1189  // RW bool; "Bold" flag (for LC_ENT_TEXTWIN)
#define LC_PROP_TSTYLE_ITALIC       1190  // RW bool; "Italic" flag (for LC_ENT_TEXTWIN)
#define LC_PROP_TSTYLE_UNDERLINE    1191  // RW bool; "Underline" flag (for LC_ENT_TEXTWIN)
#define LC_PROP_TSTYLE_STRIKEOUT    1192  // RW bool; "Strikeout" flag (for LC_ENT_TEXTWIN)
#define LC_PROP_TSTYLE__MAX         1200

// Dimension style
#define LC_PROP_DIMST__MIN          1201
#define LC_PROP_DIMST_ID            1001  // R  int64|string; Unique Identifier
#define LC_PROP_DIMST_NAME          1002  // RW string;
#define LC_PROP_DIMST_DESC          1003  // RW string;
#define LC_PROP_DIMST_DESCR         1003  // RW string;
#define LC_PROP_DIMST_DRW           1004  // R  handle;
#define LC_PROP_DIMST_DELETED       1005  // R  bool;
#define LC_PROP_DIMST_STANDARD      1205  // R  bool;
#define LC_PROP_DIMST_ADEC          1211  // RW int; Number of precision places displayed in angular dimensions
#define LC_PROP_DIMST_ASZ           1212  // RW float; Controls dimension arrowhead size and hookline size
#define LC_PROP_DIMST_AUNIT         1213  // RW int; Controls the angle format for angular dimensions
#define LC_PROP_DIMST_AZIN          1214  // RW int; Controls suppression of zeros for angular dimensions
#define LC_PROP_DIMST_BLK1          1215  // RW int|string; arrow1 type
#define LC_PROP_DIMST_BLK2          1216  // RW int|string; arrow2 type
#define LC_PROP_DIMST_CEN           1217  // RW float; Determines style of center marks for arcs or circles being dimensioned
#define LC_PROP_DIMST_CLRD          1218  // RW int; Sets color for dimension leader lines, arrowheads, dimension lines and leaders
#define LC_PROP_DIMST_CLRE          1219  // RW int; Sets color for dimension extension lines
#define LC_PROP_DIMST_CLRT          1220  // RW int; Sets color for dimension text
#define LC_PROP_DIMST_DEC           1221  // RW int; Controls the precision for a primary units dimension's tolerance values
#define LC_PROP_DIMST_DSEP          1222  // RW int; Single-character decimal separator used when creating dimensions whose unit format is decimal
#define LC_PROP_DIMST_EXE           1223  // RW float; Controls extension of extension line beyond dimension line
#define LC_PROP_DIMST_EXO           1224  // RW float; Offset of extension lines from origin points
#define LC_PROP_DIMST_GAP           1225  // RW float; Determines the gap around dimension text when the dimension line is broken to fit the text
#define LC_PROP_DIMST_LDRBLK        1226  // RW int|string; leader arrow type
#define LC_PROP_DIMST_LFAC          1227  // RW float; Global scale factor for linear dimensioning measurements
#define LC_PROP_DIMST_LWD           1228  // RW int; Dimension line lineweight 
#define LC_PROP_DIMST_LWE           1229  // RW int; Extension line lineweight
#define LC_PROP_DIMST_POST          1230  // RW string; Sets a dimension prefix or suffix for the measurement text
#define LC_PROP_DIMST_RND           1231  // RW float; Sets a rounding value for dimensions.
#define LC_PROP_DIMST_SCALE         1232  // RW float; Overall scale factor applied to dimension variables for sizes, distances and offsets
#define LC_PROP_DIMST_TAD           1233  // RW int; Determines text vertical position relative to the dimension line
#define LC_PROP_DIMST_TIH           1234  // RW int; If 1, text between extension lines is always drawn horizontally
#define LC_PROP_DIMST_TXT           1235  // RW float; Dimension text height if the current dimstyle has no fixed text height
#define LC_PROP_DIMST_TXSTY         1236  // RW handle|string; Text style      
#define LC_PROP_DIMST_TSTYLE        1236  //    LC_PROP_DIMST_TXSTY
#define LC_PROP_DIMST_LUNIT         1237  // RW int; Sets units for all dimension types except Angular
#define LC_PROP_DIMST_ZIN           1238  // RW int; Controls the suppression of zeros in the primary unit value
#define LC_PROP_DIMST__MAX          1299


// Block
#define LC_PROP_BLOCK__MIN          1301
#define LC_PROP_BLOCK_ID            1001  // R  int64|string;
#define LC_PROP_BLOCK_NAME          1002  // RW string;
#define LC_PROP_BLOCK_DESC          1003  // RW string;
#define LC_PROP_BLOCK_DESCR         1003  // RW string;
#define LC_PROP_BLOCK_DRW           1004  // R  handle; Handle to owner drawing
#define LC_PROP_BLOCK_DELETED       1005  // R  bool;
#define LC_PROP_BLOCK_X             1305  // RW float;
#define LC_PROP_BLOCK_Y             1306  // RW float;
#define LC_PROP_BLOCK_Z             1307  // RW float;
#define LC_PROP_BLOCK_UFSCALING     1308  // RW bool;
#define LC_PROP_BLOCK_UNITS         1309  // RW int;
#define LC_PROP_BLOCK_UNITSCALE     1310  // R  float;
#define LC_PROP_BLOCK_MODEL         1311  // R  bool;
#define LC_PROP_BLOCK_PAPER         1312  // R  bool;
#define LC_PROP_BLOCK_LAYOUT        1313  // R  bool;  MODEL or  PAPER
#define LC_PROP_BLOCK_STANDARD      1314  // R  bool;
#define LC_PROP_BLOCK_HIDDEN        1315  // R  bool;
#define LC_PROP_BLOCK_DIM           1316  // R  bool;
#define LC_PROP_BLOCK_HATCH         1317  // R  bool;
#define LC_PROP_BLOCK_NOBJ          1319  // R  int; number of graphic objects (not deleted) in the block
#define LC_PROP_BLOCK_NSELOBJ       1320  // R  int; number of selected objects
#define LC_PROP_BLOCK_ATTRIBS       1327  // R  bool;  "Block has attributes" flag
#define LC_PROP_BLOCK_BASE          1329  //   for event
#define LC_PROP_BLOCK__MAX          1349

// View
#define LC_PROP_VIEW__MIN           1351
#define LC_PROP_VIEW_ID             1001  // R  int64|string; Unique Identifier
#define LC_PROP_VIEW_NAME           1002  // RW string;
#define LC_PROP_VIEW_DESC           1003  // RW string;
#define LC_PROP_VIEW_DESCR          1003  // RW string;
#define LC_PROP_VIEW_DRW            1004  // R  handle;
#define LC_PROP_VIEW_DELETED        1005  // R  bool;
#define LC_PROP_VIEW_BLOCK          1355  // RW handle|string; Handle to Block|Name of Block
#define LC_PROP_VIEW_MODEL          1356  // R  bool;
#define LC_PROP_VIEW_PAPER          1358  // R  bool;
#define LC_PROP_VIEW_XMIN           1361  // R  float; Extents
#define LC_PROP_VIEW_YMIN           1362  // R  float;
#define LC_PROP_VIEW_XMAX           1363  // R  float;
#define LC_PROP_VIEW_YMAX           1364  // R  float;
#define LC_PROP_VIEW_DX             1365  // R  float; width of extents
#define LC_PROP_VIEW_DY             1366  // R  float; height of extents
#define LC_PROP_VIEW_WIDTH          1367  // R  float; width of visible area
#define LC_PROP_VIEW_W              1367  // R  float; 
#define LC_PROP_VIEW_HEIGHT         1368  // R  float; height of visible area
#define LC_PROP_VIEW_H              1368  // R  float; 
#define LC_PROP_VIEW_LEF            1369  // R  float; left of visible area
#define LC_PROP_VIEW_BOT            1370  // R  float;
#define LC_PROP_VIEW_RIG            1371  // R  float;
#define LC_PROP_VIEW_TOP            1372  // R  float;
#define LC_PROP_VIEW_PIXELSIZE      1373  // R  float;
#define LC_PROP_VIEW_PICKBOXSIZE    1374  // R  float;
#define LC_PROP_VIEW_LIMITS         1375  // RW bool;
#define LC_PROP_VIEW_COLORBACK      1376  // R  int; (COLORREF)
#define LC_PROP_VIEW_COLORFORE      1377  // R  int; (COLORREF)
#define LC_PROP_VIEW_COLORCURSOR    1378  // R  int; (COLORREF)
#define LC_PROP_VIEW_GRID           1381  // RW bool;
#define LC_PROP_VIEW_GRIDSNAP       1382  // RW bool;
#define LC_PROP_VIEW_OSNAP          1383  // RW bool;
#define LC_PROP_VIEW_OSNAPMODE      1384  // RW int;
#define LC_PROP_VIEW_PTRACK         1385  // RW bool;
#define LC_PROP_VIEW_ORTHO          1386  // RW bool;
#define LC_PROP_VIEW_ORDER          1390  // RW int;
#define LC_PROP_PAPER_SIZE          1391  // R  int; Paper size
#define LC_PROP_PAPER_ORIENT        1392  // R  int; Paper orientation 
#define LC_PROP_PAPER_W             1393  // R  float; Paper width, mm 
#define LC_PROP_PAPER_H             1394  // R  float; Paper height, mm 
#define LC_PROP_PAPER_X0            1395  // R  float; X coordinate of paper left-bottom corner 
#define LC_PROP_PAPER_Y0            1396  // R  float; Y coordinate of paper left-bottom corner 
#define LC_PROP_PAPER_INCH          1397  // RW bool; original paper units (used when import drawing from DWG)
#define LC_PROP_VIEW__MAX           1399

// Raster Image 
#define LC_PROP_IMAGE__MIN          1401 
#define LC_PROP_IMAGE_ID            1001  // R  int64|string; Unique Identifier
#define LC_PROP_IMAGE_NAME          1002  // RW string; Image name 
#define LC_PROP_IMAGE_DESC          1003  // RW string; Image description 
#define LC_PROP_IMAGE_DESCR         1003  // RW string; Image description 
#define LC_PROP_IMAGE_DRW           1004  // R  handle; Handle to owner drawing 
#define LC_PROP_IMAGE_DELETED       1005  // R  bool;
#define LC_PROP_IMAGE_FILENAME      1405  // RW string; Image filename 
#define LC_PROP_IMAGE_SIZE          1406  // R  int;    Image size, bytes 
#define LC_PROP_IMAGE_WPIX          1407  // R  int;    Image width (pixels) 
#define LC_PROP_IMAGE_HPIX          1408  // R  int;    Image height (pixels) 
#define LC_PROP_IMAGE_CBIT          1409  // R  int;    Color bits 
#define LC_PROP_IMAGE_RGB           1410  // R  bool;   RGB/Palette colors 
#define LC_PROP_IMAGE_EMBEDDED      1412  // RW bool;  saved inside a drawing   
#define LC_PROP_IMAGE_CREATED       1413  // R  bool;  // undoc
#define LC_PROP_IMAGE_COLORS        1414  // RW handle;  pointer to palette memory
#define LC_PROP_IMAGE_BITS          1415  // RW handle;  pointer to points memory 
#define LC_PROP_IMAGE_TRANSPARENT   1416  // RW bool;   // undoc
#define LC_PROP_IMAGE_TRANCOLOR     1417  // RW int;   // undoc
#define LC_PROP_IMAGE__MAX          1430 

// Multiline style
#define LC_PROP_MLSTYLE__MIN        1431
#define LC_PROP_MLSTYLE_ID          1001  // R  int64|string; Unique Identifier
#define LC_PROP_MLSTYLE_NAME        1002  // RW string;
#define LC_PROP_MLSTYLE_DESC        1003  // RW string;
#define LC_PROP_MLSTYLE_DESCR       1003  // RW string;
#define LC_PROP_MLSTYLE_DRW         1004  // R  handle; Handle to owner drawing 
#define LC_PROP_MLSTYLE_DELETED     1005  // R  bool;
#define LC_PROP_MLSTYLE_STANDARD    1436  // R  bool;
#define LC_PROP_MLSTYLE_JOINTS      1438  // RW bool; draw joins
#define LC_PROP_MLSTYLE_STARTLINE   1439  // RW bool; draw start line
#define LC_PROP_MLSTYLE_STARTARC    1440  // RW bool; draw start arc
#define LC_PROP_MLSTYLE_ENDLINE     1441  // RW bool; draw end line
#define LC_PROP_MLSTYLE_ENDARC      1442  // RW bool; draw end arc
#define LC_PROP_MLSTYLE_NLINES      1443  // R int; number of lines
#define LC_PROP_MLSTYLE_ILINE       1444  // RW int; index of current line
#define LC_PROP_MLSTYLE_OFFSET      1445  // RW float; offset of current line
#define LC_PROP_MLSTYLE_LTYPE       1446  // RW handle; linetype of current line
#define LC_PROP_MLSTYLE_COLOR       1447  // RW string; color of current line
#define LC_PROP_MLSTYLE__MAX        1460

#define LC_PROP_TABLE__MAX          2999 

// Entity common
#define LC_PROP_ENT__MIN          3001
#define LC_PROP_ENT_ID            3001  // R  int64|string; Unique Identifier
#define LC_PROP_ENT_KEY           3002  // RW int; User value
#define LC_PROP_ENT_COLOR         3003  // RW string; Color
#define LC_PROP_ENT_BCOLOR        3004  // RW string; Border Color
#define LC_PROP_ENT_COLORBYLAYER  3005  // RW bool; Color "ByLayer"
#define LC_PROP_ENT_COLORBYBLOCK  3006  // RW bool; Color "ByBlock"
#define LC_PROP_ENT_BCOLORBYLAYER 3007  // RW bool; Border Color "ByLayer"
#define LC_PROP_ENT_BCOLORBYBLOCK 3008  // RW bool; Border Color "ByBlock"
#define LC_PROP_ENT_COLORI        3009  // RW int; R bool; Color Index
#define LC_PROP_ENT_COLORT        3010  // RW int; R bool; True Color
#define LC_PROP_ENT_BCOLORI       3011  // RW int; R bool; Border Color Index
#define LC_PROP_ENT_BCOLORT       3012  // RW int; R bool; Border True Color
#define LC_PROP_ENT_LAYER         3013  // RW handle|string; Handle to Layer|Name of Layer
#define LC_PROP_ENT_LINETYPE      3014  // RW handle|string; Handle to Linetype|Name of Linetype
#define LC_PROP_ENT_LTSCALE       3015  // RW float; Linetype scale
#define LC_PROP_ENT_LWEIGHT       3016  // RW int; Lineweight
#define LC_PROP_ENT_BLOCK         3017  // R  handle|string; Handle to Block|Name of Block
#define LC_PROP_ENT_DRW           3018  // R  handle; Handle to drawing
#define LC_PROP_ENT_BORDER        3019  // RW bool;
#define LC_PROP_ENT_LOCKED        3020  // R  bool;
#define LC_PROP_ENT_FILLED        3021  // RW bool;
#define LC_PROP_ENT_VISIBLE       3022  // R  bool;
#define LC_PROP_ENT_HIDDEN        3023  // RW bool;
#define LC_PROP_ENT_BLINK         3024  // RW bool;  ???
#define LC_PROP_ENT_TYPE          3025  // R  int;
#define LC_PROP_ENT_DELETED       3026  // RW bool;
#define LC_PROP_ENT_IMMORTAL      3027  // RW bool; can't be deleted
#define LC_PROP_ENT_SELECTED      3028  // R  bool; TRUE if entity is selected
#define LC_PROP_ENT_PRIORITY      3029  // RW int64|string; priority for sorting
#define LC_PROP_ENT_XDATASIZE     3031  // RW int; size of extra data (bytes)
#define LC_PROP_ENT_XDATA         3032  // RW handle; pointer to extra data  
#define LC_PROP_ENT_XSTR          3033  // RW string; user string (uses XDATA buffer) 
#define LC_PROP_ENT_XGUID         3034  // RW string; entity's Globally Unique Identifier (uses XDATA buffer)
#define LC_PROP_ENT_Z             3035  // RW float; Z coord for 2D objects
#define LC_PROP_ENTBASE__MAX      3100

// Point
#define LC_PROP_POINT__MIN       3101
#define LC_PROP_POINT_X          3102  // RW float;
#define LC_PROP_POINT_Y          3103  // RW float;
#define LC_PROP_POINT_OWNSTYLE   3105  // RW bool;
#define LC_PROP_POINT_SIZE       3106  // RW float;
#define LC_PROP_POINT_MODE       3107  // RW int;
#define LC_PROP_POINT_BORDER     3108  // RW bool; Have border (for filled)
#define LC_PROP_POINT_POS        3109  //   for event
#define LC_PROP_POINT__MAX       3120

// Line
#define LC_PROP_LINE__MIN        3121
#define LC_PROP_LINE_X0          3121  // RW float; Start point X
#define LC_PROP_LINE_Y0          3122  // RW float; Start point Y
#define LC_PROP_LINE_Z0          3123  // RW float; Start point Z
#define LC_PROP_LINE_X1          3124  // RW float; End point X
#define LC_PROP_LINE_Y1          3125  // RW float; End point Y
#define LC_PROP_LINE_Z1          3126  // RW float; End point Z
#define LC_PROP_LINE_DX          3127  // RW float; Delta X
#define LC_PROP_LINE_DY          3128  // RW float; Delta Y
#define LC_PROP_LINE_DZ          3129  // RW float; Delta Z
#define LC_PROP_LINE_ANG         3130  // RW float; Angle 
#define LC_PROP_LINE_LEN         3131  // RW float; Length
#define LC_PROP_LINE_START       3132  //   for event
#define LC_PROP_LINE_END         3133  //   for event
#define LC_PROP_LINE__MAX        3140       

// Construction Line
#define LC_PROP_XLINE__MIN       3141
#define LC_PROP_XLINE_X0         3141  // RW float; Base point X
#define LC_PROP_XLINE_Y0         3142  // RW float; Base point Y
#define LC_PROP_XLINE_ANG        3144  // RW float; Direction angle
#define LC_PROP_XLINE_DIRX       3145  // R  float; Direction vector X
#define LC_PROP_XLINE_DIRY       3146  // R  float; Direction vector Y
#define LC_PROP_XLINE_RAY        3147  // RW bool; Ray mode
#define LC_PROP_XLINE_BASE       3148  //   for event
#define LC_PROP_XLINE__MAX       3160

// Circle
#define LC_PROP_CIRCLE__MIN      3201
#define LC_PROP_CIRCLE_X         3201  // RW float; Center point X
#define LC_PROP_CIRCLE_Y         3202  // RW float; Center point Y
#define LC_PROP_CIRCLE_RAD       3204  // RW float; Radius
#define LC_PROP_CIRCLE_DIAM      3205  // RW float; Diameter
#define LC_PROP_CIRCLE_LEN       3206  // RW float; Circumference length
#define LC_PROP_CIRCLE_AREA      3207  // RW float; Area
#define LC_PROP_CIRCLE_FILLED    3208  // RW bool; Filled circle
#define LC_PROP_CIRCLE_BORDER    3209  // RW bool; Have border (for filled)
#define LC_PROP_CIRCLE_CENTER    3210  //  for event
#define LC_PROP_CIRCLE__MAX      3230

// Arc
#define LC_PROP_ARC__MIN         3231
#define LC_PROP_ARC_X            3231  // RW float; Center point X
#define LC_PROP_ARC_Y            3232  // RW float; Center point Y
#define LC_PROP_ARC_RAD          3234  // RW float; Radius
#define LC_PROP_ARC_ANG0         3235  // RW float; Start angle
#define LC_PROP_ARC_ANGARC       3236  // RW float; Arc included angle
#define LC_PROP_ARC_ANGEND       3237  // R  float; End angle
#define LC_PROP_ARC_X0           3238  // R  float; Start point X
#define LC_PROP_ARC_Y0           3239  // R  float; Start point Y
#define LC_PROP_ARC_XEND         3241  // R  float; End point X
#define LC_PROP_ARC_YEND         3242  // R  float; End point Y
#define LC_PROP_ARC_LEN          3244  // R  float; Length
#define LC_PROP_ARC_CHLEN        3245  // R  float; Chord length
#define LC_PROP_ARC_AREA         3246  // R  float; Area
#define LC_PROP_ARC_CCW          3247  // R  bool; "Counter-ClockWise direction" flag
#define LC_PROP_ARC_FILLED       3248  // RW bool; Filled arc
#define LC_PROP_ARC_BORDER       3249  // RW bool; Have border (for filled)
#define LC_PROP_ARC_SECTOR       3250  // RW bool; Draw as sector
#define LC_PROP_ARC_CENTER       3251  //   for event
#define LC_PROP_ARC__MAX         3260

// Ellipse
#define LC_PROP_ELL__MIN         3261
#define LC_PROP_ELL_X            3261  // RW float; Center point X 
#define LC_PROP_ELL_Y            3262  // RW float; Center point Y 
#define LC_PROP_ELL_R1           3264  // RW float; Radius first 
#define LC_PROP_ELL_R2           3265  // RW float; Radius second 
#define LC_PROP_ELL_RATIO        3266  // RW float; R2/R1
#define LC_PROP_ELL_ANGLE        3267  // RW float; Rotation angle 
#define LC_PROP_ELL_ANG0         3268  // RW float; Start angle (for elliptical arc) 
#define LC_PROP_ELL_ANGARC       3269  // RW float; Arc included angle. Positive - counter-clockwise,
#define LC_PROP_ELL_ANGEND       3270  // R  float; End angle
#define LC_PROP_ELL_X0           3271  // R  float; Start point X
#define LC_PROP_ELL_Y0           3272  // R  float; Start point Y
#define LC_PROP_ELL_XEND         3273  // R  float; End point X
#define LC_PROP_ELL_YEND         3274  // R  float; End point Y
#define LC_PROP_ELL_LEN          3276  // R  float; Length 
#define LC_PROP_ELL_AREA         3277  // R  float; Area 
#define LC_PROP_ELL_FULL         3278  // R  bool;  "Full ellipse" flag 
#define LC_PROP_ELL_CCW          3279  // R  bool;  "CounterClockWise direction" flag 
#define LC_PROP_ELL_FILLED       3280  // RW bool;  "Filled ellipse" flag 
#define LC_PROP_ELL_BORDER       3281  // RW bool;  "Have border" flag (for filled) 
#define LC_PROP_ELL_SECTOR       3282  // RW bool;  "Draw as sector" flag 
#define LC_PROP_ELL_CENTER       3283  //   for event
#define LC_PROP_ELL__MAX         3299
#define LC_PROP_ENTPART1__MAX    3299  // Point, Line, Xline, Circle, Arc, Ellipse

// Lightweight Polyline 
#define LC_PROP_PLINE__MIN       3301
#define LC_PROP_PLINE_FIT        3301  // RW int; Fit type
#define LC_PROP_PLINE_NVERS      3302  // R  int; Number of vertices
#define LC_PROP_PLINE_NPATHS     3303  // R  int; Number of paths
#define LC_PROP_PLINE_WIDTH      3305  // RW float|bool; Constant width | Has const width
#define LC_PROP_PLINE_RADIUS     3306  // RW float|bool; Constant radius (for rounded polyline) | Has const radius
#define LC_PROP_PLINE_CHAMFER    3307  // RW bool; Chamfer or arc (for rounded polyline)
#define LC_PROP_PLINE_LEN        3308  // R  float; Length
#define LC_PROP_PLINE_AREA       3309  // R  float; Area
#define LC_PROP_PLINE_CLOSED     3310  // RW bool; Closed polyline
#define LC_PROP_PLINE_FILLED     3311  // RW bool; Filled polyline (for closed)
#define LC_PROP_PLINE_BORDER     3312  // RW bool; Have border (for filled)
#define LC_PROP_PLINE_HASANG0    3313  // RW bool; Has start angle (for fit spline)
#define LC_PROP_PLINE_ANG0       3314  // RW float; Start angle (for fit spline)
#define LC_PROP_PLINE_HASANG2    3315  // RW bool; Has end angle (for fit spline)
#define LC_PROP_PLINE_ANG2       3316  // RW float; End angle (for fit spline)
#define LC_PROP_PLINE_CW         3317  // R  bool; "ClockWise direction" flag
#define LC_PROP_PLINE_CCW        3318  // R  bool; "Counter-ClockWise direction" flag
#define LC_PROP_PLINE_Z          3319  // RW float; Evevalion (Z)
#define LC_PROP_PLINE_CONSTZ     3320  // R  bool; all vertices have same Z
#define LC_PROP_PLINE__MAX       3350

// Multiline Polyline 
#define LC_PROP_MLINE__MIN       3351
#define LC_PROP_MLINE_STYLE      3351  // RW handle|string; Handle to mline style|Name of mline style
#define LC_PROP_MLINE_JUST       3352  // RW int; justification LC_MLINE_TOP and other
#define LC_PROP_MLINE_SCALE      3353  // RW float; mline scale
#define LC_PROP_MLINE_NVERS      3354  // R  int; Number of vertices
#define LC_PROP_MLINE_CLOSED     3355  // RW bool; closed polyline
#define LC_PROP_MLINE_FIT        3356  // RW int; Fit type
#define LC_PROP_MLINE_LEN        3357  // R  float; Length
#define LC_PROP_MLINE_AREA       3358  // R  float; Area
#define LC_PROP_MLINE__MAX       3370

// Rectangle
#define LC_PROP_RECT__MIN        3371
#define LC_PROP_RECT_X           3371  // RW float; Center X
#define LC_PROP_RECT_Y           3372  // RW float; Center Y 
#define LC_PROP_RECT_W           3374  // RW float; Width 
#define LC_PROP_RECT_H           3375  // RW float; Height 
#define LC_PROP_RECT_ANGLE       3376  // RW float; Rotation angle 
#define LC_PROP_RECT_RAD         3377  // RW float; Corners radius 
#define LC_PROP_RECT_CHAMFER     3378  // RW bool; Chamfer at corners 
#define LC_PROP_RECT_FILLED      3379  // RW bool; "Filled rectangle" flag 
#define LC_PROP_RECT_BORDER      3380  // RW bool; Has border (for filled rectangle) 
#define LC_PROP_RECT_LEN         3381  // R  float; Perimeter 
#define LC_PROP_RECT_AREA        3382  // R  float; Area 
#define LC_PROP_RECT_CENTER      3383  //   for event
#define LC_PROP_RECT__MAX        3399     

// Text (LC_ENT_TEXT)
#define LC_PROP_TEXT__MIN        3401
#define LC_PROP_TEXT_STYLE       3401  // RW handle|string; Handle to text style|Name of text style
#define LC_PROP_TEXT_STR         3402  // RW string; Text content
#define LC_PROP_TEXT_STRT        3403  // R  string; Text content (with translated codes)
#define LC_PROP_TEXT_LEN         3404  // R  int; Number of characters in the Text string
#define LC_PROP_TEXT_ALIGN       3405  // RW int; Alignment type
#define LC_PROP_TEXT_X           3406  // RW float; Insertion point X
#define LC_PROP_TEXT_Y           3407  // RW float; Insertion point Y
#define LC_PROP_TEXT_H           3411  // RW float; Height
#define LC_PROP_TEXT_WSCALE      3412  // RW float; Width factor (horisontal scale)
#define LC_PROP_TEXT_ANGLE       3413  // RW float; Rotation angle
#define LC_PROP_TEXT_OBLIQUE     3414  // RW float; Oblique angle
#define LC_PROP_TEXT_CHARSPACE   3415  // RW float;
#define LC_PROP_TEXT_WRECT       3416  // R  float; Width of a text bounding rectange
#define LC_PROP_TEXT_X0          3417  // R  float; X coordinate of left-bottom corner
#define LC_PROP_TEXT_Y0          3418  // R  float; Y coordinate of left-bottom corner
#define LC_PROP_TEXT_XFIT        3419  // RW float; 
#define LC_PROP_TEXT_YFIT        3420  // RW float;
#define LC_PROP_TEXT_UPDOWN      3421  // RW bool; Indication "Upside-down text"
#define LC_PROP_TEXT_BACKWARD    3422  // RW bool; Indication "Backward text"
#define LC_PROP_TEXT_POS         3423  //   for event
#define LC_PROP_TEXT_FIT         3424  //   for event
#define LC_PROP_TEXT__MAX        3430

// TextWin (LC_ENT_TEXTWIN)
#define LC_PROP_TEXTW__MIN       3431
#define LC_PROP_TEXTW_STYLE      3431  // RW handle|string; Handle to text style|Name of text style
#define LC_PROP_TEXTW_STR        3432  // RW string; Text content
#define LC_PROP_TEXTW_STRT       3433  // R  string; Text content (with translated codes)
#define LC_PROP_TEXTW_LEN        3434  // R  int; Number of characters in the Text string
#define LC_PROP_TEXTW_ALIGN      3435  // RW int; Alignment type
#define LC_PROP_TEXTW_X          3436  // RW float; Insertion point X
#define LC_PROP_TEXTW_Y          3437  // RW float; Insertion point Y
#define LC_PROP_TEXTW_H          3438  // RW float; Height
#define LC_PROP_TEXTW_PIXH       3439  // RW bool; Pixel Height (Label mode)
#define LC_PROP_TEXTW_LABEL      3439  // RW bool; Pixel Height (Label mode)
#define LC_PROP_TEXTW_DX         3440  // RW int; Offset X (valid if Pixel Height is true)
#define LC_PROP_TEXTW_DY         3441  // RW int; Offset Y (valid if Pixel Height is true)
#define LC_PROP_TEXTW_WSCALE     3442  // RW float; Width factor (horisontal scale)
#define LC_PROP_TEXTW_ANGLE      3443  // RW float; Rotation angle
#define LC_PROP_TEXTW_POS        3444  //   for event
#define LC_PROP_TEXTW_OFFSET     3445  //   for event
#define LC_PROP_TEXTW__MAX       3450

// Multitine Text (LC_ENT_MTEXT)
#define LC_PROP_MTEXT__MIN       3451
#define LC_PROP_MTEXT_STYLE      3451  // RW handle|string;
#define LC_PROP_MTEXT_STR        3452  // RW string;
#define LC_PROP_MTEXT_LEN        3453  // R  int;
#define LC_PROP_MTEXT_ALIGN      3454  // RW int;
#define LC_PROP_MTEXT_X          3455  // RW float;
#define LC_PROP_MTEXT_Y          3456  // RW float;
#define LC_PROP_MTEXT_H          3458  // RW float;
#define LC_PROP_MTEXT_WSCALE     3459  // RW float;
#define LC_PROP_MTEXT_ANGLE      3460  // RW float;
#define LC_PROP_MTEXT_OBLIQUE    3461  // RW float;
#define LC_PROP_MTEXT_WRECT      3462  // R  float;
#define LC_PROP_MTEXT_HRECT      3463  // R  float;
#define LC_PROP_MTEXT_WRAPWIDTH  3464  // RW float;
#define LC_PROP_MTEXT_LINESPACE  3465  // RW float;
#define LC_PROP_MTEXT_CHARSPACE  3466  // RW float;
#define LC_PROP_MTEXT_MIRROR     3467  // RW bool;
#define LC_PROP_MTEXT_POS        3468  //   for event
#define LC_PROP_MTEXT__MAX       3470

// Arc Text (LC_ENT_ARCTEXT)
#define LC_PROP_ATEXT__MIN       3481
#define LC_PROP_ATEXT_STYLE      3481  // RW handle|string; Text style
#define LC_PROP_ATEXT_STR        3482  // RW string;
#define LC_PROP_ATEXT_STRT       3483  // R  string; Text content (with translated codes)
#define LC_PROP_ATEXT_LEN        3484  // R  int;
#define LC_PROP_ATEXT_X          3485  // RW float; Center X
#define LC_PROP_ATEXT_Y          3486  // RW float; Center Y
#define LC_PROP_ATEXT_RADIUS     3487  // RW float; Radius
#define LC_PROP_ATEXT_ANGLE      3488  // RW float; text Angle
#define LC_PROP_ATEXT_ANGSTA     3489  // R  float; Start angle
#define LC_PROP_ATEXT_ANGEND     3490  // R  float; End angle
#define LC_PROP_ATEXT_CW         3491  // RW bool; Clockwise direction
#define LC_PROP_ATEXT_H          3492  // RW float; Height
#define LC_PROP_ATEXT_WSCALE     3493  // RW float; Width scale
#define LC_PROP_ATEXT_CHARSPACE  3494  // RW float; Charspace
#define LC_PROP_ATEXT_ALIGN      3495  // RW int;
#define LC_PROP_ATEXT_POS        3496  //   for event
#define LC_PROP_ATEXT__MAX       3499
#define LC_PROP_ENTPART2__MAX    3499  // Polyline, Multiline, Rect, Text, TextWin, MText, ArcText

// Attribute definition & Attribute
#define LC_PROP_ATT__MIN         3501
#define LC_PROP_ATT_MODE         3501  // RW int; 
#define LC_PROP_ATT_TSTYLE       3502  // RW handle|string; Handle to text style|Name of text style
#define LC_PROP_ATT_TAG          3503  // RW string;
#define LC_PROP_ATT_PROMPT       3504  // RW string;
#define LC_PROP_ATT_DEFVAL       3505  // RW string;
#define LC_PROP_ATT_ALIGN        3506  // RW int; Alignment type
#define LC_PROP_ATT_X            3507  // RW float; Insertion point X
#define LC_PROP_ATT_Y            3508  // RW float; Insertion point Y
#define LC_PROP_ATT_Z            3509  // RW float; Insertion point Z
#define LC_PROP_ATT_H            3510  // RW float; Height
#define LC_PROP_ATT_WSCALE       3511  // RW float; Width factor (horisontal scale)
#define LC_PROP_ATT_ANGLE        3512  // RW float; Rotation angle
#define LC_PROP_ATT_OBLIQUE      3513  // RW float; Oblique angle
#define LC_PROP_ATT_X0           3514  // R  float; X coordinate of left-bottom corner
#define LC_PROP_ATT_Y0           3515  // R  float; Y coordinate of left-bottom corner
#define LC_PROP_ATT_XFIT         3516  // RW float; 
#define LC_PROP_ATT_YFIT         3517  // RW float;
#define LC_PROP_ATT_UPDOWN       3518  // RW bool; Indication "Upside-down text"
#define LC_PROP_ATT_BACKWARD     3519  // RW bool; Indication "Backward text"
#define LC_PROP_ATT_POS          3520  //   for event
#define LC_PROP_ATT_FIT          3521  //   for event
#define LC_PROP_ATT__MAX         3530

// Block Reference
#define LC_PROP_BLKREF__MIN      3531
#define LC_PROP_BLKREF_BLOCK     3531  // RW handle|string; Handle to Block|Name of Block
#define LC_PROP_BLKREF_X         3532  // RW float; Insertion point X
#define LC_PROP_BLKREF_Y         3533  // RW float; Insertion point Y
#define LC_PROP_BLKREF_SCALE     3535  // RW float;
#define LC_PROP_BLKREF_SCX       3536  // RW float;
#define LC_PROP_BLKREF_SCY       3537  // RW float;
#define LC_PROP_BLKREF_UFSCALE   3539  // R  bool;
#define LC_PROP_BLKREF_ANGLE     3540  // RW float;
#define LC_PROP_BLKREF_ATTRIBS   3541  // R  bool;  "Block has attributes" flag
#define LC_PROP_BLKREF_POS       3542  //   for event
#define LC_PROP_BLKREF__MAX      3550 

// Raster Image reference
#define LC_PROP_IMGREF__MIN      3551
#define LC_PROP_IMGREF_IMAGE     3551  // RW handle|string;  Handle to Image | Name of Image 
#define LC_PROP_IMGREF_X         3552  // RW float; X coordinate of left-bottom corner 
#define LC_PROP_IMGREF_Y         3553  // RW float; Y coordinate of left-bottom corner 
#define LC_PROP_IMGREF_XC        3554  // RW float; X coordinate of center point 
#define LC_PROP_IMGREF_YC        3555  // RW float; Y coordinate of center point
#define LC_PROP_IMGREF_W         3556  // RW float; Width 
#define LC_PROP_IMGREF_H         3557  // RW float; Height 
#define LC_PROP_IMGREF_SCALE     3558  // RW float; unoform scale, units per pixel 
#define LC_PROP_IMGREF_SCX       3559  // RW float; Horizontal scale, units per pixel 
#define LC_PROP_IMGREF_SCY       3560  // RW float; Vertical scale, units per pixel 
#define LC_PROP_IMGREF_ANGLE     3561  // RW float; rotation angle, around left-bottom corner 
#define LC_PROP_IMGREF_UFSCALE   3562  // RW bool;  "Uniform scale" flag 
#define LC_PROP_IMGREF_BORDER    3563  // RW bool;  "Draw a border" flag 
#define LC_PROP_IMGREF_POS       3564  //   for event
#define LC_PROP_IMGREF_PATH      3566  //   _PW_
#define LC_PROP_IMGREF__MAX      3571

// ECW / Jpeg2000 Image
#define LC_PROP_ECW__MIN         3601  
#define LC_PROP_ECW_FILENAME     3601  // R  string; Image filename
#define LC_PROP_ECW_LOADED       3602  // R  bool; "Image is loaded" flag 
#define LC_PROP_ECW_XMIN         3603  // R  float; X coordinate of left-bottom corner
#define LC_PROP_ECW_YMIN         3604  // R  float; Y coordinate of left-bottom corner
#define LC_PROP_ECW_XMAX         3605  // R  float; X coordinate of right-top corner
#define LC_PROP_ECW_YMAX         3606  // R  float; Y coordinate of right-top corner
#define LC_PROP_ECW_W            3607  // R  float; Width (drawing units)
#define LC_PROP_ECW_H            3608  // R  float; Height (drawing units)
#define LC_PROP_ECW_WPIX         3609  // R  int; Width (pixels)
#define LC_PROP_ECW_HPIX         3610  // R  int; Height (pixels)
#define LC_PROP_ECW_CBIT         3611  // R  int; Color bits
#define LC_PROP_ECW_SCALEX       3612  // R  float;
#define LC_PROP_ECW_SCALEY       3613  // R  float;
#define LC_PROP_ECW_BORDER       3614  // RW bool; "Draw a border" flag 
#define LC_PROP_ECW__MAX         3630 

// Hatch
#define LC_PROP_HATCH__MIN       3631  
#define LC_PROP_HATCH_NAME       3631  // RW string; Pattern name or "SOLID"
#define LC_PROP_HATCH_PATTERN    3632  // RW string; Pattern data for custom pattern
#define LC_PROP_HATCH_SCALE      3633  // RW float; Hatch scale 
#define LC_PROP_HATCH_ANGLE      3634  // RW float; Rotation angle 
#define LC_PROP_HATCH_SIZE       3635  // R  float; Pattern size
#define LC_PROP_HATCH_ASSOC      3636  // RW bool; "Associative hatch" flag 
#define LC_PROP_HATCH_SOLID      3637  // RW bool; Solid fill
#define LC_PROP_HATCH_CUSTOM     3638  // R  bool; Custom pattern
#define LC_PROP_HATCH_NPT        3639  // R  int; number of points
#define LC_PROP_HATCH_NLOOP      3640  // R  int; number of loops
#define LC_PROP_HATCH_NHPL       3641  // R  int; number of pattern lines
#define LC_PROP_HATCH_IHPL       3642  // W  int; set index of active pattern line
#define LC_PROP_HPL_ANGLE        3651  // R  float;
#define LC_PROP_HPL_X0           3652  // R  float;
#define LC_PROP_HPL_Y0           3653  // R  float;
#define LC_PROP_HPL_DX           3654  // R  float;
#define LC_PROP_HPL_DY           3655  // R  float;
#define LC_PROP_HPL_NDASH        3656  // R  int;
#define LC_PROP_HPL_DASH1        3657  // R  float;
#define LC_PROP_HPL_DASH2        3658  // R  float;
#define LC_PROP_HPL_DASH3        3659  // R  float;
#define LC_PROP_HPL_DASH4        3660  // R  float;
#define LC_PROP_HPL_DASH5        3661  // R  float;
#define LC_PROP_HPL_DASH6        3662  // R  float;
#define LC_PROP_HPL_DASH7        3663  // R  float;
#define LC_PROP_HPL_DASH8        3664  // R  float;
#define LC_PROP_HATCH__MAX       3699 

// Viewport on Paper Space
#define LC_PROP_VPORT__MIN       3701
#define LC_PROP_VPORT_LEF        3703  // RW float; Left side
#define LC_PROP_VPORT_BOT        3704  // RW float; Bottom side
#define LC_PROP_VPORT_RIG        3705  //
#define LC_PROP_VPORT_TOP        3706  //
#define LC_PROP_VPORT_W          3707  // RW float; Width
#define LC_PROP_VPORT_H          3708  // RW float; Height
#define LC_PROP_VPORT_VX         3709  // RW float; View center X on the projection
#define LC_PROP_VPORT_VY         3710  // RW float; View center Y on the projection
#define LC_PROP_VPORT_VSCALE     3711  // RW float; View scale
#define LC_PROP_VPORT_VANGLE     3712  // RW float; View rotation angle
#define LC_PROP_VPORT_FIXSCALE   3713  // RW bool; fixed scale
#define LC_PROP_VPORT_NFL        3714  // R  int; Number of frozen layers
#define LC_PROP_VPORT_RECT       3715  //   for event
#define LC_PROP_VPORT_VRECT      3716  //   for event
#define LC_PROP_VPORT__MAX       3740
#define LC_PROP_ENTPART3__MAX    3740  // Attrib, BlockRef, ImageRef, ECW, Hatch, Viewport 


// Clothoid
#define LC_PROP_CLOT__MIN        3721   
#define LC_PROP_CLOT_X1          3721  // RW float;
#define LC_PROP_CLOT_Y1          3722  // RW float;
#define LC_PROP_CLOT_ANG1        3723  // RW float;
#define LC_PROP_CLOT_X2          3724  // RW float;
#define LC_PROP_CLOT_Y2          3725  // RW float;
#define LC_PROP_CLOT_ANG2        3726  // RW float;
#define LC_PROP_CLOT_XC          3727  // R  float;
#define LC_PROP_CLOT_YC          3728  // R  float;
#define LC_PROP_CLOT_R1          3729  // R  float;
#define LC_PROP_CLOT_R2          3730  // R  float;
#define LC_PROP_CLOT_LEN         3731  // R  float;
#define LC_PROP_CLOT_INCANG      3732  // R  float;
#define LC_PROP_CLOT__MAX        3740   

// Quadratic bezier curve
#define LC_PROP_BEZ__MIN         3741           
#define LC_PROP_BEZ_X1           3741  // RW float;
#define LC_PROP_BEZ_Y1           3742  // RW float;
#define LC_PROP_BEZ_ANG1         3743  // RW float;
#define LC_PROP_BEZ_X2           3744  // RW float;
#define LC_PROP_BEZ_Y2           3745  // RW float;
#define LC_PROP_BEZ_ANG2         3746  // RW float;
#define LC_PROP_BEZ_XV           3747  // RW float;
#define LC_PROP_BEZ_YV           3748  // RW float;
#define LC_PROP_BEZ_LEN          3749  // R  float;
#define LC_PROP_BEZ_INCANG       3750  // R  float;
#define LC_PROP_BEZ__MAX         3760           
 
// Road Plan
#define LC_PROP_RPLAN__MIN       3771   
#define LC_PROP_RPLAN_LEN        3771  // R  float;
#define LC_PROP_RPLAN_MARKARC    3772  // RW bool;
#define LC_PROP_RPLAN_MARKSIZE   3773  // RW float;
#define LC_PROP_RPLAN_NVERS      3781  // R  int;
#define LC_PROP_RPLAN_IVER       3782  // RW int;
#define LC_PROP_RPVER__MIN       3783   
#define LC_PROP_RPVER_X          3783  // R  float;
#define LC_PROP_RPVER_Y          3784  // R  float;
#define LC_PROP_RPVER_ANGLE      3785  // R  float;
#define LC_PROP_RPVER_DIRANG     3786  // R  float;
#define LC_PROP_RPVER_R          3787  // R  float;
#define LC_PROP_RPVER_L1         3788  // R  float;
#define LC_PROP_RPVER_L2         3789  // R  float;
#define LC_PROP_RPVER_ANGL1      3790  // R  float;
#define LC_PROP_RPVER_ANGARC     3791  // R  float;
#define LC_PROP_RPVER_ANGL2      3792  // R  float;
#define LC_PROP_RPVER_BISEC      3793  // R  float;
#define LC_PROP_RPVER_ARCLEN     3794  // R  float;
#define LC_PROP_RPVER_CURLEN     3795  // R  float;
#define LC_PROP_RPVER_LINE1      3796  // R  float;
#define LC_PROP_RPVER_T1         3797  // R  float;
#define LC_PROP_RPVER_T2         3798  // R  float;
#define LC_PROP_RPVER_LINE2      3799  // R  float;
#define LC_PROP_RPVER_DIST1      3800  // R  float;
#define LC_PROP_RPVER_DIST2      3801  // R  float;
#define LC_PROP_RPLAN__MAX       3830   

// Triangulated Irregular Network (TIN)
#define LC_PROP_TIN__MIN         3831
#define LC_PROP_TIN_XMIN         3831  // R  float; Xmin
#define LC_PROP_TIN_XMAX         3832  // R  float; Xmax
#define LC_PROP_TIN_YMIN         3833  // R  float; Ymin
#define LC_PROP_TIN_YMAX         3834  // R  float; Ymax
#define LC_PROP_TIN_ZMIN         3835  // R  float; Zmin
#define LC_PROP_TIN_ZMAX         3836  // R  float; Zmax
#define LC_PROP_TIN_DX           3837  // R  float; delta X
#define LC_PROP_TIN_DY           3838  // R  float; delta Y
#define LC_PROP_TIN_DZ           3839  // R  float; delta Z
#define LC_PROP_TIN_NPTYPES      3840  // R  int
#define LC_PROP_TIN_NPOINTS      3841  // R  int
#define LC_PROP_TIN_NTRIANS      3842  // R  int
#define LC_PROP_TIN_SCALETRV     3843  // RW float; scale of trian.vector
#define LC_PROP_TIN_ISOSTEP      3844  // RW float; Z step of isolines 
#define LC_PROP_TIN_ZSTEP        3844  // RW float; Z step of isolines 
#define LC_PROP_TIN_FILENAME     3845  // R  string; model filename
#define LC_PROP_TIN_EMBEDDED     3846  // R  bool;
#define LC_PROP_TIN_VIEWPT       3851  // RW bool; point
#define LC_PROP_TIN_VIEWPTT      3852  // RW bool; point type name
#define LC_PROP_TIN_VIEWPTI      3853  // RW bool; point index
#define LC_PROP_TIN_VIEWPTZ      3854  // RW bool; point Z
#define LC_PROP_TIN_VIEWTR       3855  // RW bool; triangle
#define LC_PROP_TIN_VIEWTRF      3856  // RW bool; triangle filling
#define LC_PROP_TIN_VIEWTRI      3857  // RW bool; triangle's index
#define LC_PROP_TIN_VIEWTRV      3858  // RW bool; triangle's waterflow vector
#define LC_PROP_TIN_VIEWISO      3859  // RW bool; isolines
#define LC_PROP_TIN_COLTR        3860  // RW int; color for triangle's outline (COLORREF)
#define LC_PROP_TIN_COLTRI       3861  // RW int; color for triangle's index (COLORREF)
#define LC_PROP_TIN_COLTRV       3862  // RW int; color for triangle's vector (COLORREF)
#define LC_PROP_TIN_COLISO       3863  // RW int; color for isolines (COLORREF)
#define LC_PROP_TIN_PTYPE        3864  //
#define LC_PROP_TIN_OBJ          3865  // R  handle; pointer to COkTIN object  // undoc
#define LC_PROP_TIN__MAX         3880  

// 3D face
#define LC_PROP_FACE__MIN        3921
#define LC_PROP_FACE_X0          3921  // RW float; 1st point X 
#define LC_PROP_FACE_Y0          3922  // RW float; 1st point Y 
#define LC_PROP_FACE_Z0          3923  // RW float; 1st point Z 
#define LC_PROP_FACE_X1          3924  // RW float; 2nd point X 
#define LC_PROP_FACE_Y1          3925  // RW float; 2nd point Y 
#define LC_PROP_FACE_Z1          3926  // RW float; 2nd point Z 
#define LC_PROP_FACE_X2          3927  // RW float; 3rd point X 
#define LC_PROP_FACE_Y2          3928  // RW float; 3rd point Y 
#define LC_PROP_FACE_Z2          3929  // RW float; 3rd point Z 
#define LC_PROP_FACE_X3          3930  // RW float; 4th point X 
#define LC_PROP_FACE_Y3          3931  // RW float; 4th point Y 
#define LC_PROP_FACE_Z3          3932  // RW float; 4th point Z 
#define LC_PROP_FACE_EDGE1       3933  // RW bool; 1st edge visibility
#define LC_PROP_FACE_EDGE2       3934  // RW bool; 2nd edge visibility
#define LC_PROP_FACE_EDGE3       3935  // RW bool; 3rd edge visibility
#define LC_PROP_FACE_EDGE4       3936  // RW bool; 4th edge visibility
#define LC_PROP_FACE_EDGE        3937  // RW int; A combination of LC_FACE_EDGE1INVIS ... constants
#define LC_PROP_FACE_POINT       3938  //   for event
#define LC_PROP_FACE__MAX        3940  

// Dimension
#define LC_PROP_DIM__MIN         4001
#define LC_PROP_DIM_STYLE        4001  // RW handle|string; Handle to dim style|Name of dim style
#define LC_PROP_DIM_MEAS         4003  // R  float; measured value
#define LC_PROP_DIM_TEXT         4004  // RW string; 

#define LC_PROP_DIMANG_STYLE     4001  
#define LC_PROP_DIMANG_MEAS      4003  
#define LC_PROP_DIMANG_TEXT      4004  

#define LC_PROP_DIMALI_STYLE     4001  
#define LC_PROP_DIMALI_MEAS      4003  
#define LC_PROP_DIMALI_TEXT      4004  

#define LC_PROP_DIMDIA_STYLE     4001
#define LC_PROP_DIMDIA_MEAS      4003
#define LC_PROP_DIMDIA_TEXT      4004

#define LC_PROP_DIMRAD_STYLE     4001
#define LC_PROP_DIMRAD_MEAS      4003
#define LC_PROP_DIMRAD_TEXT      4004

#define LC_PROP_DIMORD_STYLE     4001
#define LC_PROP_DIMORD_MEAS      4003
#define LC_PROP_DIMORD_TEXT      4004

#define LC_PROP_DIMROT_STYLE     4001
#define LC_PROP_DIMROT_MEAS      4003
#define LC_PROP_DIMROT_TEXT      4004

#define LC_PROP_DIMANG__MIN      4011
#define LC_PROP_DIMANG_3PNT      4011  // R  bool; "3 points" mode
#define LC_PROP_DIMANG_2LINE     4012  // R  bool; "2 lines" mode
#define LC_PROP_DIMANG_CPX       4013  // RW float; center point 1
#define LC_PROP_DIMANG_CPY       4014  // RW float; 
#define LC_PROP_DIMANG_DP1X      4015  // RW float; definition point 1
#define LC_PROP_DIMANG_DP1Y      4016  // RW float; 
#define LC_PROP_DIMANG_DP2X      4017  // RW float; definition point 2
#define LC_PROP_DIMANG_DP2Y      4018  // RW float; 
#define LC_PROP_DIMANG_L1P1X     4021  // RW float; line 1 def.point 1
#define LC_PROP_DIMANG_L1P1Y     4022  // RW float; 
#define LC_PROP_DIMANG_L1P2X     4023  // RW float; line 1 def.point 2
#define LC_PROP_DIMANG_L1P2Y     4024  // RW float; 
#define LC_PROP_DIMANG_DP3X      4023
#define LC_PROP_DIMANG_DP3Y      4024
#define LC_PROP_DIMANG_L2P1X     4025  // RW float; line 2 def.point 1
#define LC_PROP_DIMANG_L2P1Y     4026  // RW float; 
#define LC_PROP_DIMANG_L2P2X     4027  // RW float; line 2 def.point 2
#define LC_PROP_DIMANG_L2P2Y     4028  // RW float; 
#define LC_PROP_DIMANG_DP4X      4027
#define LC_PROP_DIMANG_DP4Y      4028
#define LC_PROP_DIMANG_APX       4029  // RW float; arc point X
#define LC_PROP_DIMANG_APY       4030  // RW float; arc point Y
#define LC_PROP_DIMANG_EXT1      4031  // RW bool; visibility of extention line 1
#define LC_PROP_DIMANG_EXT2      4032  // RW bool; visibility of extention line 2
#define LC_PROP_DIMANG_RAD       4033  // R  float; radius of dim arc
#define LC_PROP_DIMANG_TPOS      4034  // RW float; text position on arc
#define LC_PROP_DIMANG_CP        4041  //   for event
#define LC_PROP_DIMANG_DP1       4042  //   for event
#define LC_PROP_DIMANG_DP2       4043  //   for event
#define LC_PROP_DIMANG_DP3       4044  //   for event
#define LC_PROP_DIMANG_DP4       4045  //   for event
#define LC_PROP_DIMANG_AP        4046  //   for event
#define LC_PROP_DIMANG_TP        4047  //   for event
#define LC_PROP_DIMANG__MAX      4050

#define LC_PROP_DIMALI__MIN      4051
#define LC_PROP_DIMALI_DP1X      4051  // RW float; def point 1
#define LC_PROP_DIMALI_DP1Y      4052  // RW float;
#define LC_PROP_DIMALI_DP2X      4053  // RW float; def point 2
#define LC_PROP_DIMALI_DP2Y      4054  // RW float;
#define LC_PROP_DIMALI_TPX       4055  // RW float; text point
#define LC_PROP_DIMALI_TPY       4056  // RW float;
#define LC_PROP_DIMALI_DP1       4057  //   for event
#define LC_PROP_DIMALI_DP2       4058  //   for event
#define LC_PROP_DIMALI_TP        4059  //   for event
#define LC_PROP_DIMALI__MAX      4069

#define LC_PROP_DIMDIA__MIN      4071
#define LC_PROP_DIMDIA_CPX       4071  // RW float; center point
#define LC_PROP_DIMDIA_CPY       4072  // RW float;
#define LC_PROP_DIMDIA_RPX       4073  // RW float; radial point
#define LC_PROP_DIMDIA_RPY       4074  // RW float;
#define LC_PROP_DIMDIA_FPX       4075  // R  float; far radial point
#define LC_PROP_DIMDIA_FPY       4076  // R  float;
#define LC_PROP_DIMDIA_TPX       4077  // RW float; text point
#define LC_PROP_DIMDIA_TPY       4078  // RW float;
#define LC_PROP_DIMDIA_CP        4079  //   for event
#define LC_PROP_DIMDIA_RP        4080  //   for event
#define LC_PROP_DIMDIA_TP        4081  //   for event
#define LC_PROP_DIMDIA__MAX      4085

#define LC_PROP_DIMRAD__MIN      4086
#define LC_PROP_DIMRAD_CPX       4086  // RW float; center point
#define LC_PROP_DIMRAD_CPY       4087  // RW float;
#define LC_PROP_DIMRAD_RPX       4088  // RW float; radial point
#define LC_PROP_DIMRAD_RPY       4089  // RW float;
#define LC_PROP_DIMRAD_TPX       4090  // RW float; text point
#define LC_PROP_DIMRAD_TPY       4091  // RW float;
#define LC_PROP_DIMRAD_CP        4092  //   for event
#define LC_PROP_DIMRAD_RP        4093  //   for event
#define LC_PROP_DIMRAD_TP        4094  //   for event
#define LC_PROP_DIMRAD__MAX      4099

#define LC_PROP_DIMORD__MIN      4101 
#define LC_PROP_DIMORD_XORD      4101  // RW bool; TRUE - X ordinate, FALSE - Y ordinate
#define LC_PROP_DIMORD_DPX       4102  // RW float; def point
#define LC_PROP_DIMORD_DPY       4103  // RW float; 
#define LC_PROP_DIMORD_TPX       4104  // RW float; text point
#define LC_PROP_DIMORD_TPY       4105  // RW float;
#define LC_PROP_DIMORD_DP        4106  //   for event
#define LC_PROP_DIMORD_TP        4107  //   for event
#define LC_PROP_DIMORD__MAX      4119

#define LC_PROP_DIMROT__MIN      4121
#define LC_PROP_DIMROT_ANGLE     4121  // RW float; rotation angle
#define LC_PROP_DIMROT_DP1X      4122  // RW float; def point 1
#define LC_PROP_DIMROT_DP1Y      4123  // RW float;
#define LC_PROP_DIMROT_DP2X      4124  // RW float; def point 2
#define LC_PROP_DIMROT_DP2Y      4125  // RW float;
#define LC_PROP_DIMROT_TPX       4126  // RW float; text point
#define LC_PROP_DIMROT_TPY       4127  // RW float;
#define LC_PROP_DIMROT_DP1       4128  //   for event
#define LC_PROP_DIMROT_DP2       4129  //   for event
#define LC_PROP_DIMROT_TP        4130  //   for event
#define LC_PROP_DIMROT__MAX      4139

#define LC_PROP_DIM__MAX         4300

// Leader
#define LC_PROP_LEADER__MIN      4501
#define LC_PROP_LEADER_STYLE     4502  // RW handle|string; Handle to dim style|Name of dim style
#define LC_PROP_LEADER_TEXT      4503  // RW string; 
#define LC_PROP_LEADER_ALIGN     4504  // RW int; text alignment (LC_LEADER_TLEFT and other)
#define LC_PROP_LEADER_TPX       4505  // RW float; text center X
#define LC_PROP_LEADER_TPY       4506  // RW float; text center Y
#define LC_PROP_LEADER_APX       4507  // RW float; arrow endpoint X
#define LC_PROP_LEADER_APY       4508  // RW float; arrow endpoint Y
#define LC_PROP_LEADER_P1X       4509  // R  float; land point X
#define LC_PROP_LEADER_P1Y       4510  // R  float; land point Y
#define LC_PROP_LEADER_P0X       4511  // R  float; start point X
#define LC_PROP_LEADER_P0Y       4512  // R  float; start point Y
#define LC_PROP_LEADER_LDIST     4513  // RW float; landing distance
#define LC_PROP_LEADER_VERT      4514  // RW bool; vertical line
#define LC_PROP_LEADER_CORNER    4515  // RW bool; attachment at corner
#define LC_PROP_LEADER_TBW       4516  // R  float; text box width
#define LC_PROP_LEADER_TBH       4517  // R  float; text box height
#define LC_PROP_LEADER_ATTACH    4518  //   for event
#define LC_PROP_LEADER_TP        4519  //   for event
#define LC_PROP_LEADER_AP        4520  //   for event
#define LC_PROP_LEADER__MAX      4530

#define LC_PROP_ENT__MAX         4999



// Polyline Vertex 
#define LC_PROP_VER__MIN         5001
#define LC_PROP_VER_X            5001  // RW float; Coordinate X~
#define LC_PROP_VER_Y            5002  // RW float; Coordinate Y~
#define LC_PROP_VER_Z            5003  // RW float; Coordinate Y~
#define LC_PROP_VER_ENDPATH      5005  // RW bool; "End of path" flag. Used for multipath polyline.
#define LC_PROP_VER_FIX          5006  // RW bool; "Fixed vertex" flag (for LC_PLFIT_LINQUAD). 
#define LC_PROP_VER_RADIUS       5007  // RW float; Radius value~
#define LC_PROP_VER_INDEX        5008  // R  int; index of the vertex 
#define LC_PROP_VER_FIRST        5009  // R  bool; TRUE if first vertex
#define LC_PROP_VER_LAST         5010  // R  bool; TRUE if last vertex
// for segment from current to next vertex
#define LC_PROP_VER_W0           5011  // RW float; Start width
#define LC_PROP_VER_W1           5012  // RW float; End width
#define LC_PROP_VER_SEGDX        5013  // RW float; dx
#define LC_PROP_VER_SEGDY        5014  // RW float; dy
#define LC_PROP_VER_SEGANG       5015  // RW float; angle
#define LC_PROP_VER_SEGLEN       5016  // RW float; length
#define LC_PROP_VER_BULGE        5021  // RW float; Bulge value
#define LC_PROP_VER_SEGARCANG    5022  // RW float; included angle of arc segment
#define LC_PROP_VER_SEGARCH      5023  // RW float; height of arc segment
#define LC_PROP_VER_SEGARCLEN    5024  // R  float; length of arc segment 
#define LC_PROP_VER_SEGARCRAD    5025  // R  float; radius of arc segment 
#define LC_PROP_VER_POS          5031  //   for event
#define LC_PROP_VER_PRM          5032  //   for event
#define LC_PROP_VER__MAX         5040

#define LC_PROP_TIN_PNT__MIN     5051
#define LC_PROP_TIN_PNT_I        5051  // RW int; index
#define LC_PROP_TIN_PNT_X        5052  // RW float; 
#define LC_PROP_TIN_PNT_Y        5053  // RW float; 
#define LC_PROP_TIN_PNT_Z        5054  // RW float; 
#define LC_PROP_TIN_PNT_TYPE     5055  // RW handle; 
#define LC_PROP_TIN_PNT__MAX     5060

#define LC_PROP_TIN_TR__MIN      5061
#define LC_PROP_TIN_TR_I         5061  // RW int; index
#define LC_PROP_TIN_TR_PT0       5062  // RW handle; 
#define LC_PROP_TIN_TR_PT1       5063  // RW handle; 
#define LC_PROP_TIN_TR_PT2       5064  // RW handle; 
#define LC_PROP_TIN_TR__MAX      5070

#define LC_PROP_TIN_PTYPE__MIN   5071
#define LC_PROP_TIN_PTYPE_NAME   5071  // RW string; 
#define LC_PROP_TIN_PTYPE_COLOR  5072  // RW int;
#define LC_PROP_TIN_PTYPE__MAX   5080

// Custom command 
#define LC_PROP_CMD__MIN         5101
#define LC_PROP_CMD_ID           5102  // R  int; command identifier LC_CMD_CUSTOM+n
#define LC_PROP_CMD_STEP         5103  // RW int; command step
#define LC_PROP_CMD_LCWND        5104  // R  handle; design window
#define LC_PROP_CMD_HWND         5105  // R  handle; HWND window handle 
#define LC_PROP_CMD_DRW          5106  // R  handle; drawing db
#define LC_PROP_CMD_BLOCK        5107  // R  handle; Handle to Block
#define LC_PROP_CMD_VIEW         5108  // R  handle; Handle to view
#define LC_PROP_CMD_CURSORX      5109  // R  int|float; Cursor position X (pixels)|Cursor position X (drawing's units)
#define LC_PROP_CMD_CURX         5109  // R  int|float; Cursor position X (pixels)|Cursor position X (drawing's units)
#define LC_PROP_CMD_CURSORY      5110  // R  int|float; Cursor position Y (pixels)|Cursor position Y (drawing's units)
#define LC_PROP_CMD_CURY         5110  // R  int|float; Cursor position Y (pixels)|Cursor position Y (drawing's units)
#define LC_PROP_CMD_PIXELSIZE    5111  // R  float; Current scale of the drawing in the window, units per pixel
#define LC_PROP_CMD_PICKBOXSIZE  5112  // R  float; Half-size of selecting square, in drawing units
#define LC_PROP_CMD_CURLEF       5113  // R  float; left side of selecting square, in drawing units
#define LC_PROP_CMD_CURBOT       5114  // R  float; bottom side of selecting square, in drawing units
#define LC_PROP_CMD_CURRIG       5115  // R  float; right side of selecting square, in drawing units
#define LC_PROP_CMD_CURTOP       5116  // R  float; top side of selecting square, in drawing units
#define LC_PROP_CMD_OSNAP        5117  // RW int|bool; object snap mode | Enable object snap
#define LC_PROP_CMD_OSNAPONCE    5118  // RW int; once object snap mode
#define LC_PROP_CMD_NPOINTS      5119  // R  int; number of points in the list
#define LC_PROP_CMD_INT0         5120  // RW int; user value
#define LC_PROP_CMD_INT1         5121  // RW int; user value
#define LC_PROP_CMD_INT2         5122  // RW int; user value
#define LC_PROP_CMD_INT3         5123  // RW int; user value
#define LC_PROP_CMD_INT4         5124  // RW int; user value
#define LC_PROP_CMD_INT5         5125  // RW int; user value
#define LC_PROP_CMD_INT6         5126  // RW int; user value
#define LC_PROP_CMD_INT7         5127  // RW int; user value
#define LC_PROP_CMD_INT8         5128  // RW int; user value
#define LC_PROP_CMD_INT9         5129  // RW int; user value
#define LC_PROP_CMD_FLOAT0       5130  // RW float; user value
#define LC_PROP_CMD_FLOAT1       5131  // RW float; user value
#define LC_PROP_CMD_FLOAT2       5132  // RW float; user value
#define LC_PROP_CMD_FLOAT3       5133  // RW float; user value
#define LC_PROP_CMD_FLOAT4       5134  // RW float; user value
#define LC_PROP_CMD_FLOAT5       5135  // RW float; user value
#define LC_PROP_CMD_FLOAT6       5136  // RW float; user value
#define LC_PROP_CMD_FLOAT7       5137  // RW float; user value
#define LC_PROP_CMD_FLOAT8       5138  // RW float; user value
#define LC_PROP_CMD_FLOAT9       5139  // RW float; user value
#define LC_PROP_CMD_HAND0        5140  // RW handle; user value
#define LC_PROP_CMD_HAND1        5141  // RW handle; user value
#define LC_PROP_CMD_HAND2        5142  // RW handle; user value
#define LC_PROP_CMD_HAND3        5143  // RW handle; user value
#define LC_PROP_CMD_HAND4        5144  // RW handle; user value
#define LC_PROP_CMD_HAND5        5145  // RW handle; user value
#define LC_PROP_CMD_HAND6        5146  // RW handle; user value
#define LC_PROP_CMD_HAND7        5147  // RW handle; user value
#define LC_PROP_CMD_HAND8        5148  // RW handle; user value
#define LC_PROP_CMD_HAND9        5149  // RW handle; user value
#define LC_PROP_CMD_STR          5150  // RW string; user value
#define LC_PROP_CMD__MAX         5160

// extentions for standard commands
#define LC_CMD_INSERT__MIN       5301
#define LC_CMD_INSERT_BLOCK      5301  // RW handle; Handle to the block to be inserted by LC_CMD_INSERT
#define LC_CMD_INSERT_X          5302  // RW float; Position X
#define LC_CMD_INSERT_Y          5303  // RW float; Position Y
#define LC_CMD_INSERT_SCALE      5304  // RW float; Scale
#define LC_CMD_INSERT_ANGLE      5305  // RW float; Rotation angle
#define LC_CMD_INSERT_ONS_XY     5306  // RW bool; Specify position on-screen
#define LC_CMD_INSERT_ONS_SCALE  5307  // RW bool; Specify scale on-screen
#define LC_CMD_INSERT_ONS_ANGLE  5308  // RW bool; Specify rotation angle on-screen
#define LC_CMD_INSERT_BLKREF     5309  // R  handle; Handle to inserted object (block reference) after LC_CMD_INSERT execution
#define LC_CMD_INSERT__MAX       5320

// Other
#define LC_PROP_OTHER__MIN       9001
#define LC_PROP_CMDWND_ENABLE    9001    // RW bool; Command window is enabled
#define LC_PROP_PROPWND_ENABLE   9002    // RW bool; Properties window is enabled
#define LC_PROP_PROPWND_DIVCOEF  9003    // RW float; ratio of the name/value columns widths
#define LC_PROP_OTHER__MAX       9999

// for event "EntModified"
#define LC_MOD_ENT_PROP          1   //   
#define LC_MOD_ENT_SET           2   //   
#define LC_MOD_PLINE_ADDVER      4
#define LC_MOD_PLINE_INSVER      5
#define LC_MOD_PLINE_DELVER      6
#define LC_MOD_PLINE_REVERSE     7
#define LC_MOD_RPLAN_ADDVER      10
#define LC_MOD_RPLAN_INSVER      11
#define LC_MOD_RPLAN_DELVER      12
#define LC_MOD_MLINE_ADDVER      14
#define LC_MOD_MLINE_INSVER      15
#define LC_MOD_MLINE_DELVER      16
#define LC_MOD_MLINE_REVERSE     17
#define LC_MOD_ENT_MOVE          20  //  
#define LC_MOD_ENT_ROTATE        21  //  
#define LC_MOD_ENT_SCALE         22  //  
#define LC_MOD_ENT_MIRROR        23  //  
#define LC_MOD_ENT_JOIN          24

// for event "ObjModified"
#define LC_MOD_OBJ_PROP          31
#define LC_MOD_BLOCK_PURGE       32   // 0,1,2,3
#define LC_MOD_BLOCK_ADDENT      33

#define LC_MOD_DRW_PROP          51

#ifndef _ONLY_LCAPI_DEFINES

//*****************************************************************************
//*****************************************************************************
//
//                        LITECAD FUNCTIONS
//
//*****************************************************************************
//*****************************************************************************
#define LCAPI _stdcall 

// Initialization
BOOL    LCAPI lcInitialize    ();
BOOL    LCAPI lcUninitialize  (BOOL bSaveConfig);
HANDLE  LCAPI lcAddFontRes    (HANDLE hModule, int idResource, LPCWSTR szFontName);
HANDLE  LCAPI lcAddFontFile   (LPCWSTR szFilename, LPCWSTR szFontName);
HANDLE  LCAPI lcAddFontBin    (HANDLE hData, LPCWSTR szFontName);

// GUI strings
BOOL    LCAPI lcStrAdd        (LPCWSTR szTag, LPCWSTR szText); 
BOOL    LCAPI lcStrSet        (LPCWSTR szTag, LPCWSTR szText);
LPCWSTR LCAPI lcStrGet        (LPCWSTR szTag);                   
BOOL    LCAPI lcStrFileLoad   (LPCWSTR szFileName);
BOOL    LCAPI lcStrFileSave   (LPCWSTR szFileName, LPCWSTR szLanguage, BOOL bInit);

// Objects properties
BOOL    LCAPI lcPropGetBool   (HANDLE hObject, int idProp);
int     LCAPI lcPropGetInt    (HANDLE hObject, int idProp);
double  LCAPI lcPropGetFloat  (HANDLE hObject, int idProp);
LPCWSTR LCAPI lcPropGetStr    (HANDLE hObject, int idProp);
int     LCAPI lcPropGetStrA   (HANDLE hObject, int idProp, char* szBuf, int BufSize);
HANDLE  LCAPI lcPropGetHandle (HANDLE hObject, int idProp);
BOOL    LCAPI lcPropPutBool   (HANDLE hObject, int idProp, BOOL bValue);
BOOL    LCAPI lcPropPutInt    (HANDLE hObject, int idProp, int Value);
BOOL    LCAPI lcPropPutFloat  (HANDLE hObject, int idProp, double Value);
BOOL    LCAPI lcPropPutStr    (HANDLE hObject, int idProp, LPCWSTR szValue);
BOOL    LCAPI lcPropPutHandle (HANDLE hObject, int idProp, HANDLE hValue);

// Drawing 
HANDLE LCAPI lcCreateDrawing      ();
BOOL   LCAPI lcDeleteDrawing      (HANDLE hDrw);
BOOL   LCAPI lcDrwNew             (HANDLE hDrw, LPCWSTR szFileName, HANDLE hLcWnd);
BOOL   LCAPI lcDrwNewT            (HANDLE hDrw, LPCWSTR szFileName, LPCWSTR szTemplate, HANDLE hLcWnd);
BOOL   LCAPI lcDrwLoad            (HANDLE hDrw, LPCWSTR szFileName, HWND hWnd, HANDLE hLcWnd);
BOOL   LCAPI lcDrwLoadMem         (HANDLE hDrw, HANDLE hMem, HANDLE hLcWnd);
BOOL   LCAPI lcDrwInsert          (HANDLE hDrw, LPCWSTR szFileName, int Overwrite, HWND hWnd);
BOOL   LCAPI lcDrwSave            (HANDLE hDrw, LPCWSTR szFileName, BOOL bBak, HWND hWnd); 
int    LCAPI lcDrwSaveMem         (HANDLE hDrw, HANDLE hMem, int MemSize); 
BOOL   LCAPI lcDrwSaveExploded    (HANDLE hDrw, LPCWSTR szFileName, BOOL bBak, HWND hWnd); 
BOOL   LCAPI lcDrwPurge           (HANDLE hDrw); 
BOOL   LCAPI lcDrwRegenViews      (HANDLE hDrw, HANDLE hEnt);
BOOL   LCAPI lcDrwSortObjects     (HANDLE hDrw, int ObjType);
BOOL   LCAPI lcDrwClearXData      (HANDLE hDrw, int ObjType, int Mode);
BOOL   LCAPI lcDrwResolveBlocks   (HANDLE hDrw, WCHAR* szError);  // undoc

HANDLE LCAPI lcDrwAddLayer        (HANDLE hDrw, LPCWSTR szName, LPCWSTR szColor, HANDLE hLtype, int Lweight);
HANDLE LCAPI lcDrwAddLinetype     (HANDLE hDrw, LPCWSTR szName, LPCWSTR szDefinition);
HANDLE LCAPI lcDrwAddLinetypeF    (HANDLE hDrw, LPCWSTR szName, LPCWSTR szFileName, LPCWSTR szLtypeName);
HANDLE LCAPI lcDrwAddTextStyle    (HANDLE hDrw, LPCWSTR szName, LPCWSTR szFontName);
HANDLE LCAPI lcDrwAddDimStyle     (HANDLE hDrw, LPCWSTR szName);
HANDLE LCAPI lcDrwAddMlineStyle   (HANDLE hDrw, LPCWSTR szName);
HANDLE LCAPI lcDrwAddImage        (HANDLE hDrw, LPCWSTR szName, LPCWSTR szFileName);
HANDLE LCAPI lcDrwAddImage2       (HANDLE hDrw, LPCWSTR szName, int Width, int Height, int nBits);
HANDLE LCAPI lcDrwAddBlock        (HANDLE hDrw, LPCWSTR szName, double X, double Y);
HANDLE LCAPI lcDrwAddBlockFromFile (HANDLE hDrw, LPCWSTR szName, LPCWSTR szFileName, int Overwrite, HWND hwParent); 
HANDLE LCAPI lcDrwAddBlockFromDrw (HANDLE hDrw, LPCWSTR szName, HANDLE hDrw2, int Overwrite, HWND hwParent);
HANDLE LCAPI lcDrwAddBlockFile    (HANDLE hDrw, LPCWSTR szName, LPCWSTR szFileName, int Overwrite, HWND hwParent);
HANDLE LCAPI lcDrwAddViewPaper    (HANDLE hDrw, LPCWSTR szName, int PaperSize, int Orient, double Width, double Height);

BOOL   LCAPI lcDrwDeleteObject    (HANDLE hDrw, HANDLE hObject);
HANDLE LCAPI lcDrwGetFirstObject  (HANDLE hDrw, int ObjType);
HANDLE LCAPI lcDrwGetNextObject   (HANDLE hDrw, HANDLE hObject);
HANDLE LCAPI lcDrwGetObjectByID   (HANDLE hDrw, int ObjType, int Id);
HANDLE LCAPI lcDrwGetObjectByIDH  (HANDLE hDrw, int ObjType, LPCWSTR szId);
HANDLE LCAPI lcDrwGetObjectByName (HANDLE hDrw, int ObjType, LPCWSTR szName);
int    LCAPI lcDrwCountObjects    (HANDLE hDrw, int ObjType);
HANDLE LCAPI lcDrwGetViewByBlock  (HANDLE hDrw, HANDLE hBlock);
HANDLE LCAPI lcDrwGetEntByID      (HANDLE hDrw, int Id);
HANDLE LCAPI lcDrwGetEntByIDH     (HANDLE hDrw, LPCWSTR szId);
HANDLE LCAPI lcDrwGetEntByKey     (HANDLE hDrw, int Key);

// View
BOOL   LCAPI lcViewSetRect        (HANDLE hView, double Xcen, double Ycen, double Width, double Height);
BOOL   LCAPI lcViewSetRect2       (HANDLE hView, double Lef, double Bot, double Rig, double Top);
BOOL   LCAPI lcViewSetLimits      (HANDLE hView, double Xmin, double Ymin, double Xmax, double Ymax);  // undoc
BOOL   LCAPI lcViewSetGrid        (HANDLE hView, double X0, double Y0, double dX, double dY);
BOOL   LCAPI lcViewRegen          (HANDLE hView, HANDLE hEnt);
BOOL   LCAPI lcViewSetPaperSize   (HANDLE hView, int PaperSize, int Orient, double Width, double Height);
HANDLE LCAPI lcViewGetEntByPoint  (HANDLE hView, double X, double Y, double Delta, int Mode);
int    LCAPI lcViewGetEntsByRect  (HANDLE hView, double Lef, double Bot, double Rig, double Top, BOOL bCross, int MaxNum);
HANDLE LCAPI lcViewGetEntity      (int iEnt);
BOOL   LCAPI lcViewRasterize      (HANDLE hView, LPCWSTR szFileName, double Lef, double Bot, double Rig, double Top, double Scal);
int    LCAPI lcViewRasterizeMem   (HANDLE hView, HANDLE hMem, double Lef, double Bot, double Rig, double Top, double Scal);
BOOL   LCAPI lcViewDrawMarker     (HANDLE hView, double X, double Y);   // !!! undoc
BOOL   LCAPI lcViewDrawLine       (HANDLE hView, double X0, double Y0, double X1, double Y1);  // !!! undoc
BOOL   LCAPI lcViewDrawXline      (HANDLE hView, double X0, double Y0, double X1, double Y1, BOOL bRay);  // !!! undoc
BOOL   LCAPI lcViewDrawRect       (HANDLE hView, double X0, double Y0, double X1, double Y1);  // !!! undoc
BOOL   LCAPI lcViewPrint          (HANDLE hView, HDC hPrintDC, double Lef, double Bot, double Rig, double Top, double Scal, double PapLef, double PapTop);

// Mline style
BOOL   LCAPI lcMLStyleAddLine   (HANDLE hStyle, double Offset, LPCWSTR szColor, HANDLE hLtype);
BOOL   LCAPI lcMLStyleDelLine   (HANDLE hStyle, int iLine);
BOOL   LCAPI lcMLStyleSortLines (HANDLE hStyle);

// Image 
BOOL   LCAPI lcImageSetPixelRGB (HANDLE hImage, int X, int Y, int Red, int Green, int Blue);      
BOOL   LCAPI lcImageSetPixelI   (HANDLE hImage, int X, int Y, int iColor);                        
BOOL   LCAPI lcImageGetPixelRGB (HANDLE hImage, int X, int Y, int* pRed, int* pGreen, int* pBlue);
BOOL   LCAPI lcImageGetPixelI   (HANDLE hImage, int X, int Y, int* piColor);                      
BOOL   LCAPI lcImageSetPalColor (HANDLE hImage, int iColor, int Red, int Green, int Blue);        
BOOL   LCAPI lcImageGetPalColor (HANDLE hImage, int iColor, int* pRed, int* pGreen, int* pBlue);  
BOOL   LCAPI lcImageSetTranColor (HANDLE hImage, BOOL bTransparent, int Red, int Green, int Blue);
BOOL   LCAPI lcImageResize      (HANDLE hImage, int Width, int Height);

// Layer
BOOL   LCAPI lcLayerClear  (HANDLE hLayer, HANDLE hBlock);

// Add graphic objects into a block
BOOL   LCAPI lcBlockClear       (HANDLE hBlock, HANDLE hLayer);
BOOL   LCAPI lcBlockPurge       (HANDLE hBlock);
BOOL   LCAPI lcBlockSortEnts    (HANDLE hBlock, BOOL bByLayers);
HANDLE LCAPI lcBlockAddPoint    (HANDLE hBlock, double X, double Y);
HANDLE LCAPI lcBlockAddPoint2   (HANDLE hBlock, double X, double Y, int PtMode, double PtSize);
HANDLE LCAPI lcBlockAddXline    (HANDLE hBlock, double X, double Y, double Angle, BOOL bRay);
HANDLE LCAPI lcBlockAddXline2P  (HANDLE hBlock, double X, double Y, double X2, double Y2, BOOL bRay);
HANDLE LCAPI lcBlockAddLine     (HANDLE hBlock, double X1, double Y1, double X2, double Y2);
HANDLE LCAPI lcBlockAddLineDir  (HANDLE hBlock, double X, double Y, double Angle, double Dist);
HANDLE LCAPI lcBlockAddLineTan  (HANDLE hBlock, HANDLE hEnt1, HANDLE hEnt2, int Mode);
HANDLE LCAPI lcBlockAddPolyline (HANDLE hBlock, int FitType, BOOL bClosed, BOOL bFilled);
HANDLE LCAPI lcBlockAddSpline   (HANDLE hBlock, BOOL bClosed, BOOL bFilled);
HANDLE LCAPI lcBlockAddMline    (HANDLE hBlock, int FitType, BOOL bClosed);
HANDLE LCAPI lcBlockAddRect     (HANDLE hBlock, double Xc, double Yc, double Width, double Height, double Angle, BOOL bFilled);
HANDLE LCAPI lcBlockAddRect2    (HANDLE hBlock, double Left, double Bottom, double Width, double Height, double Rad, BOOL bFilled);
HANDLE LCAPI lcBlockAddCircle   (HANDLE hBlock, double X, double Y, double Radius, BOOL bFilled);
HANDLE LCAPI lcBlockAddArc      (HANDLE hBlock, double X, double Y, double Radius, double StartAngle, double ArcAngle);
HANDLE LCAPI lcBlockAddArc3P    (HANDLE hBlock, double X1, double Y1, double X2, double Y2, double X3, double Y3);
HANDLE LCAPI lcBlockAddEllipse  (HANDLE hBlock, double X, double Y, double R1, double R2, double RotAngle, double StartAngle, double ArcAngle);
HANDLE LCAPI lcBlockAddText     (HANDLE hBlock, LPCWSTR szText, double X, double Y);
HANDLE LCAPI lcBlockAddText2    (HANDLE hBlock, LPCWSTR szText, double X, double Y, int Align, double H, double WScale, double RotAngle, double Oblique);
HANDLE LCAPI lcBlockAddTextWin  (HANDLE hBlock, LPCWSTR szText, double X, double Y);
HANDLE LCAPI lcBlockAddTextWin2 (HANDLE hBlock, LPCWSTR szText, double X, double Y, int Align, double H, double WScale, double RotAngle, double Oblique);
HANDLE LCAPI lcBlockAddMText    (HANDLE hBlock, LPCWSTR szText, double X, double Y, double WrapWidth, int Align, double RotAngle, double H, double WScale);
HANDLE LCAPI lcBlockAddArcText  (HANDLE hBlock, LPCWSTR szText, double X, double Y, double Radius, double StartAngle, BOOL bClockwise, double H, double WScale, int Align);
HANDLE LCAPI lcBlockAddBlockRef (HANDLE hBlock, HANDLE hRefBlock, double X, double Y, double Scal, double Angle);
HANDLE LCAPI lcBlockAddBlockRefID  (HANDLE hBlock, int idRefBlock, double X, double Y, double Scal, double Angle);  // undoc
HANDLE LCAPI lcBlockAddBlockRefIDH (HANDLE hBlock, LPCWSTR szIdRefBlock, double X, double Y, double Scal, double Angle);  // undoc
HANDLE LCAPI lcBlockAddImageRef (HANDLE hBlock, HANDLE hImage, double X, double Y, double Width, double Height, BOOL bBorder);
HANDLE LCAPI lcBlockAddEcw      (HANDLE hBlock, LPCWSTR szFileName);
HANDLE LCAPI lcBlockAddAttDef   (HANDLE hBlock, int Mode, LPCWSTR szTag, LPCWSTR szPrompt, LPCWSTR szDefVal, double X, double Y, int Align, double H, double WScale, double RotAngle, double Oblique);
HANDLE LCAPI lcBlockAddHatch    (HANDLE hBlock, LPCWSTR szFileName, LPCWSTR szPatName, double Scal, double Angle);
HANDLE LCAPI lcBlockAddViewport (HANDLE hBlock, double Lef, double Bot, double Width, double Height, double DrwPntX, double DrwPntY, double DrwScale, double DrwAngle);
HANDLE LCAPI lcBlockAddFace     (HANDLE hBlock, int Flags, double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2);
HANDLE LCAPI lcBlockAddFace4    (HANDLE hBlock, int Flags, double x0, double y0, double z0, double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3);
HANDLE LCAPI lcBlockAddLeader   (HANDLE hBlock, LPCWSTR szText, double Xt, double Yt, double LandDist, double Xa, double Ya, int Attach, int Align);
HANDLE LCAPI lcBlockAddDimRot   (HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Xt, double Yt, double Angle, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimHor   (HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Yt, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimVer   (HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Xt, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimAli   (HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Xt, double Yt, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimAli2  (HANDLE hBlock, double X0, double Y0, double X1, double Y1, double Dt, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimOrd   (HANDLE hBlock, double Xd, double Yd, double Xt, double Yt, bool bX, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimRad   (HANDLE hBlock, double Xc, double Yc, double Xr, double Yr, double Xt, double Yt, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimRad2  (HANDLE hBlock, double Xc, double Yc, double R, double Angle, double TextOff, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimDia   (HANDLE hBlock, double Xc, double Yc, double Xr, double Yr, double Xt, double Yt, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimDia2  (HANDLE hBlock, double Xc, double Yc, double R, double Angle, double TextOff, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimAng   (HANDLE hBlock, double Xc, double Yc, double X1, double Y1, double X2, double Y2, double Xa, double Ya, double TextPos, LPCWSTR szText);
HANDLE LCAPI lcBlockAddDimAng2  (HANDLE hBlock, double X1, double Y1, double X2, double Y2, double X3, double Y3, double X4, double Y4, double Xa, double Ya, double TextPos, LPCWSTR szText);
HANDLE LCAPI lcBlockAddRPlan    (HANDLE hBlock);
HANDLE LCAPI lcBlockAddBezier   (HANDLE hBlock, double X1, double Y1, double Angle1, double X2, double Y2, double Angle2);
HANDLE LCAPI lcBlockAddTIN      (HANDLE hBlock);
HANDLE LCAPI lcBlockAddClone    (HANDLE hBlock, HANDLE hEnt); 

// Retrieve graphic objects from a block
HANDLE LCAPI lcBlockGetFirstEnt (HANDLE hBlock);
HANDLE LCAPI lcBlockGetNextEnt  (HANDLE hBlock, HANDLE hEnt);
HANDLE LCAPI lcBlockGetLastEnt  (HANDLE hBlock);
HANDLE LCAPI lcBlockGetPrevEnt  (HANDLE hBlock, HANDLE hEnt);
HANDLE LCAPI lcBlockGetEntByID  (HANDLE hBlock, int Id);
HANDLE LCAPI lcBlockGetEntByIDH (HANDLE hBlock, LPCWSTR szId);
HANDLE LCAPI lcBlockGetEntByKey (HANDLE hBlock, int Key);
HANDLE LCAPI lcBlockGetTIN      (HANDLE hBlock, int Index);   // undoc

// Selection
BOOL   LCAPI lcBlockUnselect    (HANDLE hBlock);
BOOL   LCAPI lcBlockSelectEnt   (HANDLE hBlock, HANDLE hEntity, BOOL bSelect);
BOOL   LCAPI lcBlockSelErase    (HANDLE hBlock);
BOOL   LCAPI lcBlockSelMove     (HANDLE hBlock, double dX, double dY, BOOL bCopy, BOOL bNewSelect);
BOOL   LCAPI lcBlockSelScale    (HANDLE hBlock, double X0, double Y0, double Scal, BOOL bCopy, BOOL bNewSelect);
BOOL   LCAPI lcBlockSelRotate   (HANDLE hBlock, double X0, double Y0, double Angle, BOOL bCopy, BOOL bNewSelect);
BOOL   LCAPI lcBlockSelMirror   (HANDLE hBlock, double X1, double Y1, double X2, double Y2, BOOL bCopy, BOOL bNewSelect);
BOOL   LCAPI lcBlockSelExplode  (HANDLE hBlock);
HANDLE LCAPI lcBlockSelJoin     (HANDLE hBlock, double Delta);
HANDLE LCAPI lcBlockGetFirstSel (HANDLE hBlock);
HANDLE LCAPI lcBlockGetNextSel  (HANDLE hBlock);

// Graphic object modify
BOOL   LCAPI lcEntErase     (HANDLE hEnt, BOOL bErase); 
BOOL   LCAPI lcEntMove      (HANDLE hEnt, double dX, double dY); 
BOOL   LCAPI lcEntScale     (HANDLE hEnt, double X0, double Y0, double Scal); 
BOOL   LCAPI lcEntRotate    (HANDLE hEnt, double X0, double Y0, double Angle);
BOOL   LCAPI lcEntMirror    (HANDLE hEnt, double X1, double Y1, double X2, double Y2);
BOOL   LCAPI lcEntExplode   (HANDLE hEnt, BOOL bSelect);
BOOL   LCAPI lcEntOffset    (HANDLE hEnt, double Dist); 
BOOL   LCAPI lcEntToTop     (HANDLE hEnt);
BOOL   LCAPI lcEntToBottom  (HANDLE hEnt);
BOOL   LCAPI lcEntToAbove   (HANDLE hEnt, HANDLE hEnt2);
BOOL   LCAPI lcEntToUnder   (HANDLE hEnt, HANDLE hEnt2);
BOOL   LCAPI lcEntGetGrip   (HANDLE hEnt, int iGrip, double* pX, double* pY); 
BOOL   LCAPI lcEntPutGrip   (HANDLE hEnt, int iGrip, double X, double Y);
BOOL   LCAPI lcEntUpdate    (HANDLE hEnt);      
BOOL   LCAPI lcEntCopyBase  (HANDLE hEnt, HANDLE hEntFrom);

int    LCAPI lcIntersection   (HANDLE hEnt, HANDLE hEnt2);
BOOL   LCAPI lcInterGetPoint  (int iPoint, double* pX, double* pY);

// Polyline Vertices
HANDLE LCAPI lcPlineAddVer      (HANDLE hPline, HANDLE hVer, double X, double Y);
HANDLE LCAPI lcPlineAddVer2     (HANDLE hPline, HANDLE hVer, double X, double Y, double Param, double W0, double W1);
HANDLE LCAPI lcPlineAddVerDir   (HANDLE hPline, HANDLE hVer, double Ang, double Length);
BOOL   LCAPI lcPlineDeleteVer   (HANDLE hPline, HANDLE hVer);
HANDLE LCAPI lcPlineGetFirstVer (HANDLE hPline);
HANDLE LCAPI lcPlineGetNextVer  (HANDLE hPline, HANDLE hVer);
HANDLE LCAPI lcPlineGetLastVer  (HANDLE hPline);
HANDLE LCAPI lcPlineGetPrevVer  (HANDLE hPline, HANDLE hVer);
HANDLE LCAPI lcPlineGetVer      (HANDLE hPline, int Index);
HANDLE LCAPI lcPlineGetVerPt    (HANDLE hPline, double X, double Y, double Delta);
HANDLE LCAPI lcPlineGetSeg      (HANDLE hPline, double X, double Y, double Delta);
BOOL   LCAPI lcPlineReverse     (HANDLE hPline);
BOOL   LCAPI lcPlineSimple      (HANDLE hPline, BOOL bSimple, int nLines);
int    LCAPI lcPlineContainPoint(HANDLE hPline, double X, double Y);
BOOL   LCAPI lcPlineGetRoundPrm (HANDLE hPline, HANDLE hVer, double* px0, double* py0, double* pBulge, double* px1, double* py1);   // undoc (dwg plugin)

// Mline Vertices
HANDLE LCAPI lcMlineAddVer      (HANDLE hMline, HANDLE hVer, double X, double Y);
HANDLE LCAPI lcMlineAddVerDir   (HANDLE hMline, HANDLE hVer, double Ang, double Length);
BOOL   LCAPI lcMlineDeleteVer   (HANDLE hMline, HANDLE hVer);
HANDLE LCAPI lcMlineGetFirstVer (HANDLE hMline);
HANDLE LCAPI lcMlineGetNextVer  (HANDLE hMline, HANDLE hVer);
HANDLE LCAPI lcMlineGetLastVer  (HANDLE hMline);
HANDLE LCAPI lcMlineGetPrevVer  (HANDLE hMline, HANDLE hVer);
HANDLE LCAPI lcMlineGetVer      (HANDLE hMline, int Index);
HANDLE LCAPI lcMlineGetVerPt    (HANDLE hMline, double X, double Y, double Delta);
HANDLE LCAPI lcMlineGetSeg      (HANDLE hMline, double X, double Y, double Delta);   // undoc
BOOL   LCAPI lcMlineReverse     (HANDLE hMline);

// RPlan functions
HANDLE LCAPI lcRPlanAddVer      (HANDLE hRPlan, double X, double Y);
BOOL   LCAPI lcRPlanSetCurve    (HANDLE hVer, double Radius, double LenClot1, double LenClot2);
BOOL   LCAPI lcRPlanSetPos      (HANDLE hVer, double X, double Y);
BOOL   LCAPI lcRPlanDeleteVer   (HANDLE hRPlan, HANDLE hVer);
HANDLE LCAPI lcRPlanGetFirstVer (HANDLE hRPlan);
HANDLE LCAPI lcRPlanGetNextVer  (HANDLE hRPlan, HANDLE hVer);
HANDLE LCAPI lcRPlanGetLastVer  (HANDLE hRPlan);
HANDLE LCAPI lcRPlanGetPrevVer  (HANDLE hRPlan, HANDLE hVer);
HANDLE LCAPI lcRPlanGetVer      (HANDLE hRPlan, int Index);
BOOL   LCAPI lcRPlanGetPoint    (HANDLE hRPlan, double Dist, double* pX, double* pY, double* pAngle, int* pSide);
BOOL   LCAPI lcRPlanGetDist     (HANDLE hRPlan, double X, double Y, double* pX2, double* pY2, double* pDist, double* pOffset);

// Viewport
BOOL   LCAPI lcVportSetView     (HANDLE hVport, double Xcen, double Ycen, double Scal, double Angle);
BOOL   LCAPI lcVportFrolClear   (HANDLE hVport);
BOOL   LCAPI lcVportFrolAdd     (HANDLE hVport, HANDLE hLayer);
HANDLE LCAPI lcVportFrolGet     (HANDLE hVport, int iLayer);
BOOL   LCAPI lcVportIsFrol      (HANDLE hVport, HANDLE hLayer);

// Block attribute
HANDLE LCAPI lcBlkRefAddAtt      (HANDLE hBlockRef, LPCWSTR szTag, LPCWSTR szValue);    // undoc
HANDLE LCAPI lcBlkRefGetFirstAtt (HANDLE hBlockRef);
HANDLE LCAPI lcBlkRefGetNextAtt  (HANDLE hBlockRef, HANDLE hAttrib);
HANDLE LCAPI lcBlkRefGetAtt      (HANDLE hBlockRef, LPCWSTR szTag);

// Hatch
BOOL   LCAPI lcHatchSetPattern   (HANDLE hHatch, LPCWSTR szFileName, LPCWSTR szPatName, double Scal, double Angle);
BOOL   LCAPI lcHatchBoundStart   (HANDLE hHatch);
BOOL   LCAPI lcHatchBoundPoint   (HANDLE hHatch, double X, double Y);
BOOL   LCAPI lcHatchBoundEndLoop (HANDLE hHatch); 
BOOL   LCAPI lcHatchBoundEnd     (HANDLE hHatch); 
BOOL   LCAPI lcHatchPatStart     (HANDLE hHatch); 
BOOL   LCAPI lcHatchPatLine      (HANDLE hHatch, double Angle, double x0, double y0, double dx, double dy, int nDash, double L0, double L1, double L2, double L3, double L4, double L5, double L6, double L7);
BOOL   LCAPI lcHatchPatEnd       (HANDLE hHatch);
int    LCAPI lcHatchGetLoopSize  (HANDLE hHatch, int iLoop);
BOOL   LCAPI lcHatchGetPoint     (HANDLE hHatch, int iPnt, double* pX, double* pY);

// Rectangle
int    LCAPI lcRectGetPolyline   (HANDLE hRect, double* pX, double* pY, double* pBulge);

// Construction line
BOOL   LCAPI lcXlinePutDir  (HANDLE hXline, double X, double Y);

// TIN object
BOOL   LCAPI lcTinClear          (HANDLE hTin, BOOL bOnlyTrians);
BOOL   LCAPI lcTinLoad           (HANDLE hTin, LPCWSTR szFileName, BOOL bEmbed);
BOOL   LCAPI lcTinSave           (HANDLE hTin, LPCWSTR szFileName, BOOL bOverwriteExist);
HANDLE LCAPI lcTinAddPtype       (HANDLE hTin, LPCWSTR szName, LPCWSTR szNotes, int Color);
HANDLE LCAPI lcTinAddPoint       (HANDLE hTin, HANDLE hPtype, double X, double Y, double Z);
HANDLE LCAPI lcTinAddTrian       (HANDLE hTin, HANDLE hPt0, HANDLE hPt1, HANDLE hPt2);
BOOL   LCAPI lcTinNormalize      (HANDLE hTin);
BOOL   LCAPI lcTinGetZ           (HANDLE hTin, double X, double Y, double* pZ);
int    LCAPI lcTinInterLine      (HANDLE hTin, double X0, double Y0, double X1, double Y1);
BOOL   LCAPI lcTinInterGetPoint  (HANDLE hTin, int iPnt, double* pX, double* pY, double* pZ);
BOOL   LCAPI lcTinDelPtype       (HANDLE hTin, HANDLE hPtype);
BOOL   LCAPI lcTinDelPoint       (HANDLE hTin, HANDLE hPoint);
BOOL   LCAPI lcTinDelTrian       (HANDLE hTin, HANDLE hTrian);
HANDLE LCAPI lcTinPtypeGetFirst  (HANDLE hTin);
HANDLE LCAPI lcTinPtypeGetNext   (HANDLE hTin, HANDLE hPtype);
HANDLE LCAPI lcTinPtypeGetByName (HANDLE hTin, LPCWSTR szName);
BOOL   LCAPI lcTinPtypeDialog    (HANDLE hTin, HWND hWnd, BOOL bReadOnly);
HANDLE LCAPI lcTinPointGetFirst  (HANDLE hTin);
HANDLE LCAPI lcTinPointGetNext   (HANDLE hTin, HANDLE hPoint);
HANDLE LCAPI lcTinPointGetByPos  (HANDLE hTin, double X, double Y, double Delta);
HANDLE LCAPI lcTinTrianGetFirst  (HANDLE hTin);
HANDLE LCAPI lcTinTrianGetNext   (HANDLE hTin, HANDLE hTrian);
HANDLE LCAPI lcTinTrianGetByPos  (HANDLE hTin, double X, double Y);


// Design window
HANDLE LCAPI lcCreateWindow      (HWND  hWndParent, int Style, int Left, int Top, int Width, int Height);
BOOL   LCAPI lcDeleteWindow      (HANDLE hLcWnd);
BOOL   LCAPI lcWndResize         (HANDLE hLcWnd, int Left, int Top, int Width, int Height);
BOOL   LCAPI lcWndSelectView     (HANDLE hLcWnd, HANDLE hView);
BOOL   LCAPI lcWndZoomRect       (HANDLE hLcWnd, double Left, double Bottom, double Right, double Top);
BOOL   LCAPI lcWndZoomScale      (HANDLE hLcWnd, double Scal);
BOOL   LCAPI lcWndZoomMove       (HANDLE hLcWnd, double DX, double DY);
BOOL   LCAPI lcWndRedraw         (HANDLE hLcWnd);
BOOL   LCAPI lcWndSetFocus       (HANDLE hLcWnd);
BOOL   LCAPI lcWndExeCommand     (HANDLE hLcWnd, int Command, int CmdParam);
BOOL   LCAPI lcWndCoordFromDrw   (HANDLE hLcWnd, double Xdrw, double Ydrw, int* pXwin, int* pYwin);
BOOL   LCAPI lcWndCoordToDrw     (HANDLE hLcWnd, int Xwin, int Ywin, double* pXdrw, double* pYdrw);
BOOL   LCAPI lcWndGetCursorCoord (HANDLE hLcWnd, int* pXwin, int* pYwin, double* pXdrw, double* pYdrw);
HANDLE LCAPI lcWndGetEntByPoint  (HANDLE hLcWnd, int Xwin, int Ywin);
BOOL   LCAPI lcWndSetCmdwin      (HANDLE hLcWnd, HANDLE hCmdLine);
BOOL   LCAPI lcWndSetPropwin     (HANDLE hLcWnd, HANDLE hPropWnd);
BOOL   LCAPI lcWndStopCommand    (HANDLE hLcWnd);    // undoc (instead of lcWndOnClose)
BOOL   LCAPI lcWndGetPoint       (HANDLE hLcWnd, LPCWSTR szPrompt, int SnapMode, int Index, double* pX, double* pY);
BOOL   LCAPI lcWndGetPointBuf    (HANDLE hLcWnd, int Index, double* pX, double* pY);

// Coordinate convertions
BOOL   LCAPI lcCoordDrwToWnd     (HANDLE hLcWnd, double Xdrw, double Ydrw, int* pXwin, int* pYwin);
BOOL   LCAPI lcCoordWndToDrw     (HANDLE hLcWnd, int Xwin, int Ywin, double* pXdrw, double* pYdrw);

// Color from string
BOOL   LCAPI lcColorIsRGB      (LPCWSTR szColor);
int    LCAPI lcColorGetRed     (LPCWSTR szColor); 
int    LCAPI lcColorGetGreen   (LPCWSTR szColor);
int    LCAPI lcColorGetBlue    (LPCWSTR szColor);
int    LCAPI lcColorGetIndex   (LPCWSTR szColor);
BOOL   LCAPI lcColorToVal      (LPCWSTR szColor, int* pbRGB, int* pIndex, int* pR,int* pG,int* pB);
// Color palette
BOOL   LCAPI lcColorSetPalette (int Index, int R,int G,int B);
BOOL   LCAPI lcColorGetPalette (int Index, int* pR,int* pG,int* pB);

// Command Window
HANDLE LCAPI lcCreateCmdwin    (HWND hWndParent, int Left, int Top, int Width, int Height);
BOOL   LCAPI lcCmdwinResize    (HANDLE hCmdLine, int Left, int Top, int Width, int Height);
BOOL   LCAPI lcCmdwinUpdate    (HANDLE hCmdLine);  // undoc

// Properties Window
HANDLE LCAPI lcCreatePropwin   (HWND hWndParent, int Left, int Top, int Width, int Height);
BOOL   LCAPI lcPropwinResize   (HANDLE hPropWnd, int Left, int Top, int Width, int Height);
BOOL   LCAPI lcPropwinUpdate   (HANDLE hPropWnd, BOOL bSelChanged);

// Misc
int     LCAPI lcGetErrorCode    ();
LPCWSTR LCAPI lcGetErrorStr     ();
int     LCAPI lcExtractPreview  (LPCWSTR szFileName, HGLOBAL hGlob, int MaxSize);
BOOL    LCAPI lcExtractFileInfo (LPCWSTR szFileName, WCHAR* szGuid, WCHAR* szComment, int* pInt0, int* pInt1);
BOOL    LCAPI lcFilletSetLines  (double L1x0, double L1y0, double L1x1, double L1y1, double L2x0, double L2y0, double L2x1, double L2y1);
BOOL    LCAPI lcFillet          (double Rad, double Bis, double Tang);
BOOL    LCAPI lcFilletGetPoint  (int iPnt, double* pX, double* pY);
LPCWSTR LCAPI lcDgGetFileName   (HWND hWnd, int Mode);
LPCWSTR LCAPI lcDgGetValue      (HWND hWnd, int Lef, int Top, LPCWSTR szTitle, LPCWSTR szPrompt, LPCWSTR szValue);
BOOL    LCAPI lcDgGetValue2     (HWND hWnd, int Lef, int Top, LPCWSTR szTitle, LPCWSTR szPrompt, WCHAR* szValue, int MaxChar);
LPCWSTR LCAPI lcPlugGetOption   (LPCWSTR szFileName, LPCWSTR szKey);
BOOL    LCAPI lcPlugSetOption   (LPCWSTR szFileName, LPCWSTR szKey, LPCWSTR szValue, BOOL bSave);
void    LCAPI lcGetPolarPoint   (double X, double Y, double Ang, double Dist, double* pX, double* pY);
BOOL    LCAPI lcGetClientSize   (HWND hWnd, int* pWidth, int* pHeight);
void    LCAPI lcTextOut         (HDC hDC, int x, int y, LPCWSTR szText, int ColorRGB);

// Interface for Custom Commands
HANDLE LCAPI lcCreateCommand   (HANDLE hLcWnd, int Id, LPCWSTR szName, BOOL bNeedSel);
BOOL   LCAPI lcCmdExit         ();
BOOL   LCAPI lcCmdPrompt       (HANDLE hCmd, LPCWSTR szText);
HANDLE LCAPI lcCmdGetEntByPoint (HANDLE hCmd, int Xwnd, int Ywnd);
BOOL   LCAPI lcCmdSelectEnt    (HANDLE hCmd, HANDLE hEntity, BOOL bSelect);
BOOL   LCAPI lcCmdRedraw       (HANDLE hCmd);
BOOL   LCAPI lcCmdSetFocus     (HANDLE hCmd);
BOOL   LCAPI lcCmdRegen        (HANDLE hCmd, HANDLE hEnt);
BOOL   LCAPI lcCmdClearPoints  (HANDLE hCmd);
BOOL   LCAPI lcCmdAddPoint     (HANDLE hCmd, int Id, double X, double Y);
BOOL   LCAPI lcCmdGetPoint     (HANDLE hCmd, int Id, double* pX, double* pY);
BOOL   LCAPI lcCmdSetBasePoint (HANDLE hCmd, BOOL bEnable, double X, double Y);
BOOL   LCAPI lcCmdDrawLine     (HANDLE hCmd, double X0, double Y0, double X1, double Y1);
BOOL   LCAPI lcCmdDrawPickbox  (HANDLE hCmd, int Xwnd, int Ywnd);
BOOL   LCAPI lcCmdEqualPoints  (HANDLE hCmd, double X0, double Y0, double X1, double Y1, int Delta);

BOOL   LCAPI lcPaintBegin    (HANDLE hLcWnd);
BOOL   LCAPI lcPaintSetPen   (int Style, int Width, int ColorRed, int ColorGreen, int ColorBlue);
BOOL   LCAPI lcPaintSetBrush (int ColorRed, int ColorGreen, int ColorBlue);
BOOL   LCAPI lcPaintPixel    (double X, double Y, int Size, int ColorRed, int ColorGreen, int ColorBlue);
BOOL   LCAPI lcPaintPoint    (double X, double Y, int PtMode, double PtSize);
BOOL   LCAPI lcPaintLine     (double X0, double Y0, double X1, double Y1);
BOOL   LCAPI lcPaintPlineVer (double X, double Y);
BOOL   LCAPI lcPaintPline    (BOOL bClosed, BOOL bFilled, BOOL bBorder);
BOOL   LCAPI lcPaintCircle   (double X, double Y, double R, BOOL bFilled, BOOL bBorder);
BOOL   LCAPI lcPaintArc      (double X, double Y, double R, double Ang0, double AngArc);
BOOL   LCAPI lcPaintSetFont  (LPCWSTR szFontName, double Height, double Angle, bool bBold, bool bItalic, bool bUnderline, bool bStrikeOut);
BOOL   LCAPI lcPaintSetTextColor (int ColorRed, int ColorGreen, int ColorBlue);
BOOL   LCAPI lcPaintText     (LPCWSTR szText, double X, double Y, int Align);
BOOL   LCAPI lcPaintEnd      ();

// 3D surface
void   LCAPI lcSurfInitialize     (int MaxSectPnt, double AngStep);
void   LCAPI lcSurfUnInitialize   ();
void   LCAPI lcSurfClearTriangles ();
BOOL   LCAPI lcSurfAddTriangle    (double X0, double Y0, double Z0, double X1, double Y1, double Z1, double X2, double Y2, double Z2);
BOOL   LCAPI lcSurfGetZ           (double X, double Y, double* pZ);
BOOL   LCAPI lcSurfGetZ_dbg       (double X, double Y, double* pZ, double* pX0, double* pY0, double* pZ0, double* pX1, double* pY1, double* pZ1, double* pX2, double* pY2, double* pZ2);
void   LCAPI lcSurfClearPlan      ();
BOOL   LCAPI lcSurfAddPlanVer     (double X, double Y, double Bulge);
int    LCAPI lcSurfMakeSection    ();
BOOL   LCAPI lcSurfGetSectPoint   (int iPnt, double* pX, double* pY, double* pZ);

// cross-section

BOOL   LCAPI lcCSectClear        ();
BOOL   LCAPI lcCSectBegin        (int PlineType);
BOOL   LCAPI lcCSectAddPoint     (double X, double Y);
BOOL   LCAPI lcCSectEnd          ();
int    LCAPI lcCSectCalcArea     ();
BOOL   LCAPI lcCSectGetArea      (int iArea, double* pAreaVal, int* pNumPnts);
BOOL   LCAPI lcCSectGetAreaPoint (int iArea, int iPnt, double* pX, double* pY);



// Events
/******************************************************************************
* Functions to handle LiteCAD events
* 
* Client application can define special functions that LiteCAD will call
* when the defined event will happen during user's work with drawing.
* This functions are called"event handlers" and client application
* must provide it to LiteCAD by LcOnEvent... functions
* You don't need to define all event handlers, just those you want to use
*
* Below follows the definitions of syntax of event functions
* Client application must provide exactly the same syntax 
*******************************************************************************/
// window events
typedef void (CALLBACK* F_MOUSEMOVE)    (HANDLE hLcWnd, int Button, int Flags, int Xwin, int Ywin, double X, double Y);
typedef void (CALLBACK* F_MOUSEDOWN)    (HANDLE hLcWnd, int Button, int Flags, int Xwin, int Ywin, double X, double Y);
typedef void (CALLBACK* F_MOUSEUP)      (HANDLE hLcWnd, int Button, int Flags, int Xwin, int Ywin, double X, double Y);
typedef void (CALLBACK* F_MOUSEDBLCLK)  (HANDLE hLcWnd, int Button, int Flags, int Xwin, int Ywin, double X, double Y);
typedef void (CALLBACK* F_MOUSESNAP)    (HANDLE hLcWnd, double Delta, double* pX, double* pY);
typedef void (CALLBACK* F_MOUSELEAVE)   (HANDLE hLcWnd); 
typedef void (CALLBACK* F_MOUSEWHEEL)   (HANDLE hLcWnd, int Flags, int Delta);
typedef void (CALLBACK* F_KEYDOWN)      (HANDLE hLcWnd, int VirtKey, int Flags, BOOL bCtrl, BOOL bShift);
typedef void (CALLBACK* F_PAINT)        (HANDLE hLcWnd, HANDLE hView, int Mode, HDC hDC, int Left, int Top, int Right, int Bottom);
typedef void (CALLBACK* F_ZOOM)         (HANDLE hLcWnd, double Left, double Bottom, double Right, double Top, double PixelSize); 
typedef void (CALLBACK* F_SELECTVIEW)   (HANDLE hLcWnd, HANDLE hView);
typedef void (CALLBACK* F_GETPOINT)     (HANDLE hLcWnd, HANDLE hView, int Index, double X, double Y);
typedef void (CALLBACK* F_ADDCOMMAND)   (HANDLE hLcWnd);

typedef void (CALLBACK* F_CMD_START)    (HANDLE hCmd, int Prm);
typedef void (CALLBACK* F_CMD_FINISH)   (HANDLE hCmd);
typedef void (CALLBACK* F_CMD_MOUSEDOWN)(HANDLE hCmd, int Button, int Flags, int Xwin, int Ywin, double X, double Y);
typedef void (CALLBACK* F_CMD_MOUSEUP)  (HANDLE hCmd, int Button, int Flags, int Xwin, int Ywin, double X, double Y);
typedef void (CALLBACK* F_CMD_MOUSEMOVE)(HANDLE hCmd, HDC hDC, int Flags, int Xwin, int Ywin, double X, double Y);
typedef void (CALLBACK* F_CMD_STRING)   (HANDLE hCmd, LPCWSTR szStr);

typedef void (CALLBACK* F_ADDENTITY)    (HANDLE hDrw, HANDLE hBlock, HANDLE hEntity);
typedef void (CALLBACK* F_REGEN)        (HANDLE hDrw, HANDLE hView, int Percent);
typedef void (CALLBACK* F_FIOPROGRESS)  (HANDLE hDrw, int Mode, int IntVal, LPCWSTR szFileName);
typedef void (CALLBACK* F_SELECTION)    (HANDLE hDrw, HANDLE hBlock, BOOL bSelect, int nEnts, HANDLE hEnt, int nTotal);
typedef void (CALLBACK* F_PROPCHANGED)  (HANDLE hDrw, int idProp, HANDLE hObj);

typedef void (CALLBACK* F_GRIPSELECT)   (HANDLE hEnt, int iGrip, double X, double Y);
typedef void (CALLBACK* F_GRIPMOVE)     (HANDLE hEnt, int iGrip, double* pX, double* pY, double* pAngle, bool bDrag);
typedef void (CALLBACK* F_ENTERASE)     (HANDLE hEnt);
typedef void (CALLBACK* F_ENTMOVE)      (HANDLE hEnt, double DX, double DY, bool bDrag);
typedef void (CALLBACK* F_ENTROTATE)    (HANDLE hEnt, double X0, double Y0, double Angle, bool bDrag);
typedef void (CALLBACK* F_ENTSCALE)     (HANDLE hEnt, double X0, double Y0, double Scal, bool bDrag);
typedef void (CALLBACK* F_ENTMIRROR)    (HANDLE hEnt, double X1, double Y1, double X2, double Y2, bool bDrag);
typedef void (CALLBACK* F_ENTPROP)      (HANDLE hEnt, int idProp);

typedef void (CALLBACK* F_FONTREPLACE)  (HANDLE hDrw, LPCWSTR szStyleName, LPCWSTR szOrigName);
typedef void (CALLBACK* F_ADDSTR)       ();
typedef void (CALLBACK* F_HELP)         (HANDLE hDrw, int idTopic);



/******************************************************************************
* Group of functions to set EVENT HANDLERS.
* Client application must call this functions at the beginning
* of execution in order to pass for LiteCAD addresses of the
* application-defined functions that will be called on
* some LiteCAD events. There is no need to use all this
* functions, just set for those events you want to catch. 
*
* IMPORTANT!!!
* Order of the lcOnEvent... functions must be the same as above typedefs (for automatic generation OCX files)
*******************************************************************************/
void LCAPI lcEventReturnCode     (int code);
void LCAPI lcEventsEnable        (BOOL bEnable); 

void LCAPI lcOnEventMouseMove    (F_MOUSEMOVE pFunc);
void LCAPI lcOnEventMouseDown    (F_MOUSEDOWN pFunc);
void LCAPI lcOnEventMouseUp      (F_MOUSEUP pFunc);
void LCAPI lcOnEventMouseDblClk  (F_MOUSEDBLCLK pFunc);
void LCAPI lcOnEventMouseSnap    (F_MOUSESNAP pFunc);
void LCAPI lcOnEventMouseLeave   (F_MOUSELEAVE pFunc);
void LCAPI lcOnEventMouseWheel   (F_MOUSEWHEEL pFunc);
void LCAPI lcOnEventKeyDown      (F_KEYDOWN pFunc);    
void LCAPI lcOnEventPaint        (F_PAINT pFunc);
void LCAPI lcOnEventZoom         (F_ZOOM pFunc);
void LCAPI lcOnEventSelectView   (F_SELECTVIEW pFunc);
void LCAPI lcOnEventGetPoint     (F_GETPOINT pFunc);
void LCAPI lcOnEventAddCommand   (F_ADDCOMMAND pFunc);       

void LCAPI lcOnEventCmdStart     (F_CMD_START pFunc);     
void LCAPI lcOnEventCmdFinish    (F_CMD_FINISH pFunc);    
void LCAPI lcOnEventCmdMouseDown (F_CMD_MOUSEDOWN pFunc); 
void LCAPI lcOnEventCmdMouseUp   (F_CMD_MOUSEUP pFunc);   
void LCAPI lcOnEventCmdMouseMove (F_CMD_MOUSEMOVE pFunc); 
void LCAPI lcOnEventCmdString    (F_CMD_STRING pFunc);

void LCAPI lcOnEventAddEntity    (F_ADDENTITY pFunc); 
void LCAPI lcOnEventRegen        (F_REGEN pFunc);
void LCAPI lcOnEventFioProgress  (F_FIOPROGRESS pFunc);
void LCAPI lcOnEventSelection    (F_SELECTION pFunc);
void LCAPI lcOnEventPropChanged  (F_PROPCHANGED pFunc);

void LCAPI lcOnEventGripSelect   (F_GRIPSELECT pFunc);
void LCAPI lcOnEventGripMove     (F_GRIPMOVE pFunc);
void LCAPI lcOnEventEntErase     (F_ENTERASE pFunc);
void LCAPI lcOnEventEntMove      (F_ENTMOVE pFunc);
void LCAPI lcOnEventEntRotate    (F_ENTROTATE pFunc);
void LCAPI lcOnEventEntScale     (F_ENTSCALE pFunc);
void LCAPI lcOnEventEntMirror    (F_ENTMIRROR pFunc);
void LCAPI lcOnEventEntProp      (F_ENTPROP pFunc);

void LCAPI lcOnEventHelp         (F_HELP pFunc);
void LCAPI lcOnEventAddStr       (F_ADDSTR pFunc);
void LCAPI lcOnEventFontReplace  (F_FONTREPLACE pFunc);







BOOL lcLoadLib ();
void lcFreeLib ();

#endif
