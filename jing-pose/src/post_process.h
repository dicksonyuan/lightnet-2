#include <vector>
#include <opencv2/opencv.hpp>

#define POSE_MAX_PEOPLE 96
#define NET_OUT_CHANNELS 57 // 38 for pafs, 19 for parts

void render_pose_keypoints(
    cv::Mat &frame,
    const std::vector<float> &keypoints,
    std::vector<int> keyshape,
    const float threshold,
    float scale);

void connect_bodyparts(
    std::vector<float> &pose_keypoints,
    const float *const map,
    const float *const peaks,
    int mapw,
    int maph,
    const int inter_min_above_th,
    const float inter_th,
    const int min_subset_cnt,
    const float min_subset_score,
    std::vector<int> &keypoint_shape);

void find_heatmap_peaks(
    const float *src,
    float *dst,
    const int SRCW,
    const int SRCH,
    const int SRC_CH,
    const float TH);

cv::Mat create_netsize_im(
    const cv::Mat &im,
    const int netw,
    const int neth,
    float *scale);