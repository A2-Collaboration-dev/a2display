#ifndef TAPS_POSITIONS_H
#define TAPS_POSITIONS_H

#include "Rtypes.h"

typedef struct {
	Double_t x;
	Double_t y;
	UChar_t type;
} taps_pos_t;

#define NUM_TAPS_CRYSTALS 438

static const taps_pos_t taps_positions[NUM_TAPS_CRYSTALS] = {
{-3.849,4.333,1},
{-6.543,4.333,2},
{-3.849,1.667,3},
{-6.543,1.667,4},
{-9.045,7.333,1},
{-11.739,7.333,2},
{-9.045,4.667,3},
{-11.739,4.667,4},
{-9.045,1.333,1},
{-11.739,1.333,2},
{-9.045,-1.333,3},
{-11.739,-1.333,4},
{-15.588,9.000,0},
{-15.588,3.000,0},
{-15.588,-3.000,0},
{-20.785,12.000,0},
{-20.785,6.000,0},
{-20.785,0.000,0},
{-20.785,-6.000,0},
{-25.981,15.000,0},
{-25.981,9.000,0},
{-25.981,3.000,0},
{-25.981,-3.000,0},
{-25.981,-9.000,0},
{-31.177,18.000,0},
{-31.177,12.000,0},
{-31.177,6.000,0},
{-31.177,0.000,0},
{-31.177,-6.000,0},
{-31.177,-12.000,0},
{-36.373,21.000,0},
{-36.373,15.000,0},
{-36.373,9.000,0},
{-36.373,3.000,0},
{-36.373,-3.000,0},
{-36.373,-9.000,0},
{-36.373,-15.000,0},
{-41.569,24.000,0},
{-41.569,18.000,0},
{-41.569,12.000,0},
{-41.569,6.000,0},
{-41.569,0.000,0},
{-41.569,-6.000,0},
{-41.569,-12.000,0},
{-41.569,-18.000,0},
{-46.765,27.000,0},
{-46.765,21.000,0},
{-46.765,15.000,0},
{-46.765,9.000,0},
{-46.765,3.000,0},
{-46.765,-3.000,0},
{-46.765,-9.000,0},
{-46.765,-15.000,0},
{-46.765,-21.000,0},
{-51.962,30.000,0},
{-51.962,24.000,0},
{-51.962,18.000,0},
{-51.962,12.000,0},
{-51.962,6.000,0},
{-51.962,0.000,0},
{-51.962,-6.000,0},
{-51.962,-12.000,0},
{-51.962,-18.000,0},
{-51.962,-24.000,0},
{-57.158,27.000,0},
{-57.158,21.000,0},
{-57.158,15.000,0},
{-57.158,9.000,0},
{-57.158,3.000,0},
{-57.158,-3.000,0},
{-57.158,-9.000,0},
{-57.158,-15.000,0},
{-57.158,-21.000,0},
{-3.849,-1.667,1},
{-6.543,-1.667,2},
{-3.849,-4.333,3},
{-6.543,-4.333,4},
{-9.045,-4.667,1},
{-11.739,-4.667,2},
{-9.045,-7.333,3},
{-11.739,-7.333,4},
{-3.849,-7.667,1},
{-6.543,-7.667,2},
{-3.849,-10.333,3},
{-6.543,-10.333,4},
{-15.588,-9.000,0},
{-10.392,-12.000,0},
{-5.196,-15.000,0},
{-20.785,-12.000,0},
{-15.588,-15.000,0},
{-10.392,-18.000,0},
{-5.196,-21.000,0},
{-25.981,-15.000,0},
{-20.785,-18.000,0},
{-15.588,-21.000,0},
{-10.392,-24.000,0},
{-5.196,-27.000,0},
{-31.177,-18.000,0},
{-25.981,-21.000,0},
{-20.785,-24.000,0},
{-15.588,-27.000,0},
{-10.392,-30.000,0},
{-5.196,-33.000,0},
{-36.373,-21.000,0},
{-31.177,-24.000,0},
{-25.981,-27.000,0},
{-20.785,-30.000,0},
{-15.588,-33.000,0},
{-10.392,-36.000,0},
{-5.196,-39.000,0},
{-41.569,-24.000,0},
{-36.373,-27.000,0},
{-31.177,-30.000,0},
{-25.981,-33.000,0},
{-20.785,-36.000,0},
{-15.588,-39.000,0},
{-10.392,-42.000,0},
{-5.196,-45.000,0},
{-46.765,-27.000,0},
{-41.569,-30.000,0},
{-36.373,-33.000,0},
{-31.177,-36.000,0},
{-25.981,-39.000,0},
{-20.785,-42.000,0},
{-15.588,-45.000,0},
{-10.392,-48.000,0},
{-5.196,-51.000,0},
{-51.962,-30.000,0},
{-46.765,-33.000,0},
{-41.569,-36.000,0},
{-36.373,-39.000,0},
{-31.177,-42.000,0},
{-25.981,-45.000,0},
{-20.785,-48.000,0},
{-15.588,-51.000,0},
{-10.392,-54.000,0},
{-5.196,-57.000,0},
{-51.962,-36.000,0},
{-46.765,-39.000,0},
{-41.569,-42.000,0},
{-36.373,-45.000,0},
{-31.177,-48.000,0},
{-25.981,-51.000,0},
{-20.785,-54.000,0},
{-15.588,-57.000,0},
{-10.392,-60.000,0},
{1.347,-4.667,1},
{-1.347,-4.667,2},
{1.347,-7.333,3},
{-1.347,-7.333,4},
{1.347,-10.667,1},
{-1.347,-10.667,2},
{1.347,-13.333,3},
{-1.347,-13.333,4},
{6.543,-7.667,1},
{3.849,-7.667,2},
{6.543,-10.333,3},
{3.849,-10.333,4},
{0.000,-18.000,0},
{5.196,-15.000,0},
{10.392,-12.000,0},
{0.000,-24.000,0},
{5.196,-21.000,0},
{10.392,-18.000,0},
{15.588,-15.000,0},
{0.000,-30.000,0},
{5.196,-27.000,0},
{10.392,-24.000,0},
{15.588,-21.000,0},
{20.785,-18.000,0},
{0.000,-36.000,0},
{5.196,-33.000,0},
{10.392,-30.000,0},
{15.588,-27.000,0},
{20.785,-24.000,0},
{25.981,-21.000,0},
{0.000,-42.000,0},
{5.196,-39.000,0},
{10.392,-36.000,0},
{15.588,-33.000,0},
{20.785,-30.000,0},
{25.981,-27.000,0},
{31.177,-24.000,0},
{0.000,-48.000,0},
{5.196,-45.000,0},
{10.392,-42.000,0},
{15.588,-39.000,0},
{20.785,-36.000,0},
{25.981,-33.000,0},
{31.177,-30.000,0},
{36.373,-27.000,0},
{0.000,-54.000,0},
{5.196,-51.000,0},
{10.392,-48.000,0},
{15.588,-45.000,0},
{20.785,-42.000,0},
{25.981,-39.000,0},
{31.177,-36.000,0},
{36.373,-33.000,0},
{41.569,-30.000,0},
{0.000,-60.000,0},
{5.196,-57.000,0},
{10.392,-54.000,0},
{15.588,-51.000,0},
{20.785,-48.000,0},
{25.981,-45.000,0},
{31.177,-42.000,0},
{36.373,-39.000,0},
{41.569,-36.000,0},
{46.765,-33.000,0},
{10.392,-60.000,0},
{15.588,-57.000,0},
{20.785,-54.000,0},
{25.981,-51.000,0},
{31.177,-48.000,0},
{36.373,-45.000,0},
{41.569,-42.000,0},
{46.765,-39.000,0},
{51.962,-36.000,0},
{6.543,-1.667,1},
{3.849,-1.667,2},
{6.543,-4.333,3},
{3.849,-4.333,4},
{11.739,-4.667,1},
{9.045,-4.667,2},
{11.739,-7.333,3},
{9.045,-7.333,4},
{11.739,1.333,1},
{9.045,1.333,2},
{11.739,-1.333,3},
{9.045,-1.333,4},
{15.588,-9.000,0},
{15.588,-3.000,0},
{15.588,3.000,0},
{20.785,-12.000,0},
{20.785,-6.000,0},
{20.785,0.000,0},
{20.785,6.000,0},
{25.981,-15.000,0},
{25.981,-9.000,0},
{25.981,-3.000,0},
{25.981,3.000,0},
{25.981,9.000,0},
{31.177,-18.000,0},
{31.177,-12.000,0},
{31.177,-6.000,0},
{31.177,0.000,0},
{31.177,6.000,0},
{31.177,12.000,0},
{36.373,-21.000,0},
{36.373,-15.000,0},
{36.373,-9.000,0},
{36.373,-3.000,0},
{36.373,3.000,0},
{36.373,9.000,0},
{36.373,15.000,0},
{41.569,-24.000,0},
{41.569,-18.000,0},
{41.569,-12.000,0},
{41.569,-6.000,0},
{41.569,0.000,0},
{41.569,6.000,0},
{41.569,12.000,0},
{41.569,18.000,0},
{46.765,-27.000,0},
{46.765,-21.000,0},
{46.765,-15.000,0},
{46.765,-9.000,0},
{46.765,-3.000,0},
{46.765,3.000,0},
{46.765,9.000,0},
{46.765,15.000,0},
{46.765,21.000,0},
{51.962,-30.000,0},
{51.962,-24.000,0},
{51.962,-18.000,0},
{51.962,-12.000,0},
{51.962,-6.000,0},
{51.962,0.000,0},
{51.962,6.000,0},
{51.962,12.000,0},
{51.962,18.000,0},
{51.962,24.000,0},
{57.158,-27.000,0},
{57.158,-21.000,0},
{57.158,-15.000,0},
{57.158,-9.000,0},
{57.158,-3.000,0},
{57.158,3.000,0},
{57.158,9.000,0},
{57.158,15.000,0},
{57.158,21.000,0},
{6.543,4.333,1},
{3.849,4.333,2},
{6.543,1.667,3},
{3.849,1.667,4},
{11.739,7.333,1},
{9.045,7.333,2},
{11.739,4.667,3},
{9.045,4.667,4},
{6.543,10.333,1},
{3.849,10.333,2},
{6.543,7.667,3},
{3.849,7.667,4},
{15.588,9.000,0},
{10.392,12.000,0},
{5.196,15.000,0},
{20.785,12.000,0},
{15.588,15.000,0},
{10.392,18.000,0},
{5.196,21.000,0},
{25.981,15.000,0},
{20.785,18.000,0},
{15.588,21.000,0},
{10.392,24.000,0},
{5.196,27.000,0},
{31.177,18.000,0},
{25.981,21.000,0},
{20.785,24.000,0},
{15.588,27.000,0},
{10.392,30.000,0},
{5.196,33.000,0},
{36.373,21.000,0},
{31.177,24.000,0},
{25.981,27.000,0},
{20.785,30.000,0},
{15.588,33.000,0},
{10.392,36.000,0},
{5.196,39.000,0},
{41.569,24.000,0},
{36.373,27.000,0},
{31.177,30.000,0},
{25.981,33.000,0},
{20.785,36.000,0},
{15.588,39.000,0},
{10.392,42.000,0},
{5.196,45.000,0},
{46.765,27.000,0},
{41.569,30.000,0},
{36.373,33.000,0},
{31.177,36.000,0},
{25.981,39.000,0},
{20.785,42.000,0},
{15.588,45.000,0},
{10.392,48.000,0},
{5.196,51.000,0},
{51.962,30.000,0},
{46.765,33.000,0},
{41.569,36.000,0},
{36.373,39.000,0},
{31.177,42.000,0},
{25.981,45.000,0},
{20.785,48.000,0},
{15.588,51.000,0},
{10.392,54.000,0},
{5.196,57.000,0},
{51.962,36.000,0},
{46.765,39.000,0},
{41.569,42.000,0},
{36.373,45.000,0},
{31.177,48.000,0},
{25.981,51.000,0},
{20.785,54.000,0},
{15.588,57.000,0},
{10.392,60.000,0},
{1.347,7.333,1},
{-1.347,7.333,2},
{1.347,4.667,3},
{-1.347,4.667,4},
{1.347,13.333,1},
{-1.347,13.333,2},
{1.347,10.667,3},
{-1.347,10.667,4},
{-3.849,10.333,1},
{-6.543,10.333,2},
{-3.849,7.667,3},
{-6.543,7.667,4},
{0.000,18.000,0},
{-5.196,15.000,0},
{-10.392,12.000,0},
{0.000,24.000,0},
{-5.196,21.000,0},
{-10.392,18.000,0},
{-15.588,15.000,0},
{0.000,30.000,0},
{-5.196,27.000,0},
{-10.392,24.000,0},
{-15.588,21.000,0},
{-20.785,18.000,0},
{0.000,36.000,0},
{-5.196,33.000,0},
{-10.392,30.000,0},
{-15.588,27.000,0},
{-20.785,24.000,0},
{-25.981,21.000,0},
{0.000,42.000,0},
{-5.196,39.000,0},
{-10.392,36.000,0},
{-15.588,33.000,0},
{-20.785,30.000,0},
{-25.981,27.000,0},
{-31.177,24.000,0},
{0.000,48.000,0},
{-5.196,45.000,0},
{-10.392,42.000,0},
{-15.588,39.000,0},
{-20.785,36.000,0},
{-25.981,33.000,0},
{-31.177,30.000,0},
{-36.373,27.000,0},
{0.000,54.000,0},
{-5.196,51.000,0},
{-10.392,48.000,0},
{-15.588,45.000,0},
{-20.785,42.000,0},
{-25.981,39.000,0},
{-31.177,36.000,0},
{-36.373,33.000,0},
{-41.569,30.000,0},
{0.000,60.000,0},
{-5.196,57.000,0},
{-10.392,54.000,0},
{-15.588,51.000,0},
{-20.785,48.000,0},
{-25.981,45.000,0},
{-31.177,42.000,0},
{-36.373,39.000,0},
{-41.569,36.000,0},
{-46.765,33.000,0},
{-10.392,60.000,0},
{-15.588,57.000,0},
{-20.785,54.000,0},
{-25.981,51.000,0},
{-31.177,48.000,0},
{-36.373,45.000,0},
{-41.569,42.000,0},
{-46.765,39.000,0},
{-51.962,36.000,0}
};

#endif