/**
* This file is part of DSO.
* 
* Copyright 2016 Technical University of Munich and Intel.
* Developed by Jakob Engel <engelj at in dot tum dot de>,
* for more information see <http://vision.in.tum.de/dso>.
* If you use this code, please cite the respective publications as
* listed on the above website.
*
* DSO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* DSO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with DSO. If not, see <http://www.gnu.org/licenses/>.
*/



#pragma once

#include <string.h>
#include <string>
#include <cmath>


namespace dso
{
#define SOLVER_SVD (int)1
#define SOLVER_ORTHOGONALIZE_SYSTEM (int)2
#define SOLVER_ORTHOGONALIZE_POINTMARG (int)4
#define SOLVER_ORTHOGONALIZE_FULL (int)8
#define SOLVER_SVD_CUT7 (int)16
#define SOLVER_REMOVE_POSEPRIOR (int)32
#define SOLVER_USE_GN (int)64
#define SOLVER_FIX_LAMBDA (int)128
#define SOLVER_ORTHOGONALIZE_X (int)256
#define SOLVER_MOMENTUM (int)512
#define SOLVER_STEPMOMENTUM (int)1024
#define SOLVER_ORTHOGONALIZE_X_LATER (int)2048


// ============== PARAMETERS TO BE DECIDED ON COMPILE TIME =================
#define PYR_LEVELS 6
extern int pyrLevelsUsed;



extern const float setting_keyframesPerSecond;
extern const bool setting_realTimeMaxKF;
extern const float setting_maxShiftWeightT;
extern const float setting_maxShiftWeightR;
extern const float setting_maxShiftWeightRT;
extern const float setting_maxAffineWeight;
extern float setting_kfGlobalWeight;



extern const float setting_idepthFixPrior;
extern const float setting_idepthFixPriorMargFac;
extern const float setting_initialRotPrior;
extern const float setting_initialTransPrior;
extern const float setting_initialAffBPrior;
extern const float setting_initialAffAPrior;
extern const float setting_initialCalibHessian;

extern const int setting_solverMode;
extern const double setting_solverModeDelta;


extern const float setting_minIdepthH_act;
extern const float setting_minIdepthH_marg;



extern const float setting_maxIdepth;
extern const float setting_maxPixSearch;
extern float setting_desiredImmatureDensity;			// done
extern float setting_desiredPointDensity;			// done
extern const float setting_minPointsRemaining;
extern const float setting_maxLogAffFacInWindow;
extern int setting_minFrames;
extern int setting_maxFrames;
extern const int setting_minFrameAge;
extern int setting_maxOptIterations;
extern int setting_minOptIterations;
extern const float setting_thOptIterations;
extern const float setting_outlierTH;
extern const float setting_outlierTHSumComponent;



extern const int setting_pattern;
extern const float setting_margWeightFac;
extern const int setting_GNItsOnPointActivation;


extern const float setting_minTraceQuality;
extern const int setting_minTraceTestRadius;
extern const float setting_reTrackThreshold;


extern const int   setting_minGoodActiveResForMarg;
extern const int   setting_minGoodResForMarg;
extern const int   setting_minInlierVotesForMarg;




extern int setting_photometricCalibration;
extern bool setting_useExposure;
extern float setting_affineOptModeA;
extern float setting_affineOptModeB;
extern const int setting_gammaWeightsPixelSelect;



extern const bool setting_forceAceptStep;



extern const float setting_huberTH;


extern bool setting_logStuff;
extern const float benchmarkSetting_fxfyfac;
extern int benchmarkSetting_width;
extern int benchmarkSetting_height;
extern const float benchmark_varNoise;
extern const float benchmark_varBlurNoise;
extern const int benchmark_noiseGridsize;
extern const float benchmark_initializerSlackFactor;

extern const float setting_frameEnergyTHConstWeight;
extern const float setting_frameEnergyTHN;

extern const float setting_frameEnergyTHFacMedian;
extern const float setting_overallEnergyTHWeight;
extern const float setting_coarseCutoffTH;

extern const float setting_minGradHistCut;
extern float setting_minGradHistAdd;
extern const float setting_gradDownweightPerLevel;
extern const bool  setting_selectDirectionDistribution;



extern const float setting_trace_stepsize;
extern const int setting_trace_GNIterations;
extern const float setting_trace_GNThreshold;
extern const float setting_trace_extraSlackOnTH;
extern const float setting_trace_slackInterval;
extern const float setting_trace_minImprovementFactor;


extern bool setting_render_displayCoarseTrackingFull;
extern bool setting_render_renderWindowFrames;
extern bool setting_render_plotTrackingFull;
extern bool setting_render_display3D;
extern bool setting_render_displayResidual;
extern bool setting_render_displayVideo;
extern bool setting_render_displayDepth;

extern bool setting_fullResetRequested;

extern bool setting_debugout_runquiet;

extern bool disableAllDisplay;
extern bool disableReconfigure;


extern bool setting_onlyLogKFPoses;




extern bool debugSaveImages;


extern int sparsityFactor;
extern const bool goStepByStep;
extern bool plotStereoImages;
extern bool multiThreading;
extern bool onlineCam;
extern bool extDepth;

extern float freeDebugParam1;
extern float freeDebugParam2;
extern float freeDebugParam3;
extern float freeDebugParam4;
extern float freeDebugParam5;


void handleKey(char k);




extern const  int staticPattern[10][40][2];
extern const int staticPatternNum[10];
extern const int staticPatternPadding[10];




//#define patternNum staticPatternNum[setting_pattern]
//#define patternP staticPattern[setting_pattern]
//#define patternPadding staticPatternPadding[setting_pattern]

//
#define patternNum 8
#define patternP staticPattern[8]
#define patternPadding 2













}
