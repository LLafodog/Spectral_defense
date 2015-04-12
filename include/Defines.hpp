#ifndef DEFINES_HPP
#define DEFINES_HPP

#include<string>
#include<vector>

using namespace std;

static const short TILE_SIZE=32;

static const vector<string> SQUARES_ID = 
  {
    "road_h", //0
    "road_v",
    "inter4",
    "fail",
    "road_end_l",
    "road_end_t",
    "road_end_b",
    "road_end_r",
    "road_lt",
    "road_rt",
    "road_rb",
    "road_lb",
    "road_3b",
    "road_3l",
    "road_3t",
    "road_3r", // 15th 
  };

#endif // DEFINES_HPP
