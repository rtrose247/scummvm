/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "bladerunner/script/scene_script.h"

namespace BladeRunner {

static int kPoliceMazePS13TargetCount = 20;

void SceneScriptPS13::InitializeScene() {
	Police_Maze_Set_Pause_State(true);
	if (Game_Flag_Query(kFlagPS12toPS13)) {
		Scene_Loop_Start_Special(kSceneLoopModeLoseControl, 0, false);
		Scene_Loop_Set_Default(1);
		Game_Flag_Reset(kFlagPS12toPS13);
		Setup_Scene_Information(World_Waypoint_Query_X(10), World_Waypoint_Query_Y(10), World_Waypoint_Query_Z(10), 200);
	} else {
		Scene_Loop_Set_Default(1);
		Setup_Scene_Information(World_Waypoint_Query_X(11), World_Waypoint_Query_Y(11), World_Waypoint_Query_Z(11), 840);
	}

	Scene_Exit_Add_2D_Exit(0, 0, 460, 639, 479, 2);
	Scene_Exit_Add_2D_Exit(1, 0,   0,  20, 479, 3);

	Ambient_Sounds_Remove_All_Non_Looping_Sounds(0);
	Ambient_Sounds_Add_Looping_Sound(387, 50, 1, 1);
	Ambient_Sounds_Add_Looping_Sound( 54, 50, 1, 1);
	Ambient_Sounds_Add_Sound(  1, 10,  50, 16, 25, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(389,  5,  50, 16, 25, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(390,  6,  50, 16, 25, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(443,  2, 100, 14, 16, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(444,  2, 100, 14, 16, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(445,  2, 100, 14, 16, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(446,  2, 100, 14, 16, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(303,  5, 100, 17, 27, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(304,  5, 100, 17, 27, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(305,  5, 100, 17, 27, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(306,  5, 100, 17, 27, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(307,  5, 100, 17, 27, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(308,  5, 100, 17, 27, -100, 100, -101, -101, 0, 0);
}

static const int *getPoliceMazePS13TrackData46() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIObstacleReset,   kItemPS13Target1,
		kPMTIFacing,          960,
		kPMTIPosition,        0,
		kPMTIWait,            2000,
		kPMTIObstacleSet,     kItemPS13Target1,
		kPMTIPlaySound,       33, 33,
		kPMTITargetSet,       kItemPS13Target1, 1,
		kPMTIEnemySet,        kItemPS13Target1,
		kPMTIWait,            1000,
		kPMTIMove,            5,
		kPMTIWait,            500,
		kPMTIShoot,           27, 33,
		kPMTIWait,            500,
		kPMTIMove,            0,
		kPMTIObstacleReset,   kItemPS13Target1,
		kPMTIPausedReset1of2, kItemPS13Target14, kItemPS13Target15,
		kPMTIPausedSet,       kItemPS13Target1,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS13TrackData47() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIObstacleReset,   kItemPS13Target2,
		kPMTIFacing,          823,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      5000, 5000,
		kPMTIObstacleSet,     kItemPS13Target2,
		kPMTIPlaySound,       33, 33,
		kPMTITargetSet,       kItemPS13Target2, 1,
		kPMTIEnemySet,        kItemPS13Target2,
		kPMTIMove,            9,
		kPMTIWait,            2000,
		kPMTIShoot,           27, 33,
		kPMTIMove,            0,
		kPMTIObstacleReset,   kItemPS13Target2,
		kPMTIPausedReset1of2, kItemPS13Target5, kItemPS13Target7,
		kPMTIPausedSet,       kItemPS13Target2,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS13TrackData48() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIObstacleReset,   kItemPS13Target3,
		kPMTIFacing,          823,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      2000, 2000,
		kPMTIObstacleSet,     kItemPS13Target3,
		kPMTIPlaySound,       33, 33,
		kPMTITargetSet,       kItemPS13Target3, 1,
		kPMTIEnemyReset,      kItemPS13Target3,
		kPMTIMove,            9,
		kPMTIWait,            2000,
		kPMTILeave,
		kPMTIMove,            0,
		kPMTIObstacleReset,   kItemPS13Target3,
		kPMTIPausedReset1of2, kItemPS13Target8, kItemPS13Target6,
		kPMTIPausedSet,       kItemPS13Target3,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS13TrackData49() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIObstacleReset,   kItemPS13Target4,
		kPMTIFacing,          922,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      3000, 3000,
		kPMTIObstacleSet,     kItemPS13Target4,
		kPMTIPlaySound,       33, 33,
		kPMTITargetSet,       kItemPS13Target4, 1,
		kPMTIEnemySet,        kItemPS13Target4,
		kPMTIMove,            9,
		kPMTIWait,            1000,
		kPMTIShoot,           27, 33,
		kPMTIMove,            0,
		kPMTIObstacleReset,   kItemPS13Target4,
		kPMTIPausedReset1of2, kItemPS13Target9, kItemPS13Target10,
		kPMTIPausedSet,       kItemPS13Target4,
		kPMTIPosition,        0,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS13TrackData50() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIObstacleReset,   kItemPS13Target5,
		kPMTIFacing,          823,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      3000, 5000,
		kPMTIObstacleSet,     kItemPS13Target5,
		kPMTIPlaySound,       33, 33,
		kPMTITargetSet,       kItemPS13Target5, 1,
		kPMTIEnemyReset,      kItemPS13Target5,
		kPMTIMove,            9,
		kPMTIWait,            2000,
		kPMTIMove,            0,
		kPMTILeave,
		kPMTIObstacleReset,   kItemPS13Target5,
		kPMTIPausedReset1of2, kItemPS13Target2, kItemPS13Target7,
		kPMTIPausedSet,       kItemPS13Target5,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS13TrackData51() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIObstacleReset,   kItemPS13Target6,
		kPMTIFacing,          823,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      2000, 2000,
		kPMTIObstacleSet,     kItemPS13Target6,
		kPMTIPlaySound,       33, 33,
		kPMTITargetSet,       kItemPS13Target6, 1,
		kPMTIEnemySet,        kItemPS13Target6,
		kPMTIMove,            9,
		kPMTIWait,            1000,
		kPMTIShoot,           27, 33,
		kPMTIWait,            500,
		kPMTIMove,            0,
		kPMTIObstacleReset,   kItemPS13Target6,
		kPMTIPausedReset1of2, kItemPS13Target8, kItemPS13Target3,
		kPMTIPausedSet,       kItemPS13Target6,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS13TrackData52() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIObstacleReset,   kItemPS13Target7,
		kPMTIFacing,          305,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      5000, 10000,
		kPMTIObstacleSet,     kItemPS13Target7,
		kPMTIPlaySound,       33, 33,
		kPMTITargetSet,       kItemPS13Target7, 1,
		kPMTIEnemyReset,      kItemPS13Target7,
		kPMTIMove,            9,
		kPMTIWait,            500,
		kPMTIEnemySet,        kItemPS13Target7,
		kPMTIRotate,          555, 80,
		kPMTIWait,            0,
		kPMTIRotate,          833, 80,
		kPMTIWait,            1000,
		kPMTIShoot,           27, 33,
		kPMTIMove,            0,
		kPMTIObstacleReset,   kItemPS13Target7,
		kPMTIPausedReset1of2, kItemPS13Target2, kItemPS13Target5,
		kPMTIPausedSet,       kItemPS13Target7,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS13TrackData53() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIObstacleReset,   kItemPS13Target8,
		kPMTIFacing,          356,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      3000, 3000,
		kPMTIObstacleSet,     kItemPS13Target8,
		kPMTIPlaySound,       33, 33,
		kPMTITargetSet,       kItemPS13Target8, 1,
		kPMTIEnemyReset,      kItemPS13Target8,
		kPMTIMove,            5,
		kPMTIEnemySet,        kItemPS13Target8,
		kPMTIRotate,          868, 200,
		kPMTIWait,            1000,
		kPMTIShoot,           27, 33,
		kPMTIRotate,          356, 60,
		kPMTIWait,            1000,
		kPMTIMove,            0,
		kPMTIObstacleReset,   kItemPS13Target8,
		kPMTIPausedReset1of2, kItemPS13Target3, kItemPS13Target6,
		kPMTIPausedSet,       kItemPS13Target8,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS13TrackData54() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIObstacleReset,   kItemPS13Target9,
		kPMTIFacing,          512,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      10000, 20000,
		kPMTIObstacleSet,     kItemPS13Target9,
		kPMTIPlaySound,       33, 33,
		kPMTITargetSet,       kItemPS13Target9, 1,
		kPMTIEnemyReset,      kItemPS13Target9,
		kPMTIMove,            3,
		kPMTIWait,            500,
		kPMTIEnemySet,        kItemPS13Target9,
		kPMTIRotate,          768, 80,
		kPMTIWait,            1000,
		kPMTIShoot,           27, 33,
		kPMTIMove,            0,
		kPMTIObstacleReset,   kItemPS13Target9,
		kPMTIPausedReset1of2, kItemPS13Target13, kItemPS13Target10,
		kPMTIPausedSet,       kItemPS13Target9,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS13TrackData55() {
	static int trackData[] = {
		kPMTIActivate,      kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIVariableInc,   kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIObstacleReset, kItemPS13Target10,
		kPMTIObstacleReset, kItemPS13Target11,
		kPMTIObstacleReset, kItemPS13Target12,
		kPMTITargetSet,     kItemPS13Target10, 1,
		kPMTITargetSet,     kItemPS13Target11, 1,
		kPMTITargetSet,     kItemPS13Target12, 1,
		kPMTIFacing,        327,
		kPMTIPosition,      0,
		kPMTIWaitRandom,    1000, 1000,
		kPMTIPlaySound,     33, 33,
		kPMTIEnemyReset,    kItemPS13Target10,
		kPMTIObstacleSet,   kItemPS13Target10,
		kPMTIMove,          14,
		kPMTIWait,          1000,
		kPMTIPausedReset,   kItemPS13Target11,
		kPMTIObstacleReset, kItemPS13Target10,
		kPMTIObstacleSet,   kItemPS13Target11,
		kPMTIPausedSet,     kItemPS13Target10,
		kPMTIPosition,      0,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS13TrackData56() {
	static int trackData[] = {
		kPMTIFacing,        327,
		kPMTIPosition,      0,
		kPMTIObstacleSet,   kItemPS13Target11,
		kPMTIEnemyReset,    kItemPS13Target11,
		kPMTIMove,          14,
		kPMTIWait,          1000,
		kPMTIPausedReset,   kItemPS13Target12,
		kPMTIObstacleReset, kItemPS13Target11,
		kPMTIObstacleSet,   kItemPS13Target12,
		kPMTIPausedSet,     kItemPS13Target11,
		kPMTIPosition,      0,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS13TrackData57() {
	static int trackData[] = {
		kPMTIEnemySet,        kItemPS13Target12,
		kPMTIFacing,          327,
		kPMTIPosition,        0,
		kPMTIObstacleSet,     kItemPS13Target12,
		kPMTIRotate,          516, 80,
		kPMTIWait,            0,
		kPMTIRotate,          843, 80,
		kPMTIWait,            1000,
		kPMTIShoot,           27, 33,
		kPMTIWait,            500,
		kPMTIMove,            14,
		kPMTIObstacleReset,   kItemPS13Target12,
		kPMTIPausedReset1of2, kItemPS13Target13, kItemPS13Target9,
		kPMTIPausedSet,       kItemPS13Target12,
		kPMTIPosition,        0,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS13TrackData58() {
	static int trackData[] = {
		kPMTIActivate,      kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIVariableInc,   kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIObstacleReset, kItemPS13Target13,
		kPMTIFacing,        922,
		kPMTIPosition,      0,
		kPMTIWaitRandom,    3000, 3000,
		kPMTIObstacleSet,   kItemPS13Target13,
		kPMTIPlaySound,     33, 33,
		kPMTITargetSet,     kItemPS13Target13, 1,
		kPMTIEnemyReset,    kItemPS13Target13,
		kPMTIMove,          9,
		kPMTIWait,          200,
		kPMTIMove,          0,
		kPMTILeave,
		kPMTITargetSet,     kItemPS13Target13, 1,
		kPMTIEnemyReset,    kItemPS13Target13,
		kPMTIWait,          200,
		kPMTIMove,          9,
		kPMTIWait,          200,
		kPMTIMove,          0,
		kPMTILeave,
		kPMTIObstacleReset, kItemPS13Target13,
		kPMTIPausedReset,   kItemPS13Target4,
		kPMTIPausedSet,     kItemPS13Target13,
		kPMTIPosition,      0,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS13TrackData62() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIObstacleReset,   kItemPS13Target14,
		kPMTIFacing,          465,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      3000, 3000,
		kPMTIObstacleSet,     kItemPS13Target14,
		kPMTIPlaySound,       33, 33,
		kPMTITargetSet,       kItemPS13Target14, 1,
		kPMTIEnemyReset,      kItemPS13Target14,
		kPMTIMove,            14,
		kPMTIWait,            1000,
		kPMTIEnemySet,        kItemPS13Target14,
		kPMTIRotate,          650, 80,
		kPMTIWait,            0,
		kPMTIRotate,          937, 80,
		kPMTIWait,            1000,
		kPMTIShoot,           27, 33,
		kPMTIWait,            500,
		kPMTIRotate,          650, 80,
		kPMTIWait,            0,
		kPMTIRotate,          465, 80,
		kPMTIMove,            0,
		kPMTIObstacleReset,   kItemPS13Target14,
		kPMTIPausedReset1of2, kItemPS13Target1, kItemPS13Target15,
		kPMTIPausedSet,       kItemPS13Target14,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS13TrackData63() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS13TargetCounter, kPoliceMazePS13TargetCount,
		kPMTIObstacleReset,   kItemPS13Target15,
		kPMTIFacing,          465,
		kPMTIPosition,        0,
		kPMTIWait,            3000,
		kPMTIObstacleSet,     kItemPS13Target15,
		kPMTIPlaySound,       33, 33,
		kPMTITargetSet,       kItemPS13Target15, 1,
		kPMTIEnemyReset,      kItemPS13Target15,
		kPMTIMove,            9,
		kPMTIWait,            1000,
		kPMTIEnemySet,        kItemPS13Target15,
		kPMTIRotate,          710, 80,
		kPMTIWait,            0,
		kPMTIRotate,          960, 80,
		kPMTIWait,            1000,
		kPMTIShoot,           27, 33,
		kPMTIWait,            500,
		kPMTIRotate,          710, 80,
		kPMTIWait,            0,
		kPMTIRotate,          460, 80,
		kPMTIMove,            0,
		kPMTIObstacleReset,   kItemPS13Target15,
		kPMTIPausedReset1of2, kItemPS13Target1, kItemPS13Target14,
		kPMTIPausedSet,       kItemPS13Target15,
		kPMTIRestart
	};
	return trackData;
}


void SceneScriptPS13::SceneLoaded() {
	Obstacle_Object("PARKMETR01", true);
	Obstacle_Object("PARKMETR02", true);
	Obstacle_Object("PARKMETR03", true);
	Obstacle_Object("PARKMETR07", true);
	Obstacle_Object("PARKMETR08", true);
	Obstacle_Object("PARKMETR10", true);
	Obstacle_Object("PARKMETR11", true);
	Obstacle_Object("PARKMETR15", true);
	Obstacle_Object("PARKMETR16", true);
	Unclickable_Object("PARKMETR01");
	Unclickable_Object("PARKMETR02");
	Unclickable_Object("PARKMETR03");
	Unclickable_Object("PARKMETR07");
	Unclickable_Object("PARKMETR08");
	Unclickable_Object("PARKMETR10");
	Unclickable_Object("PARKMETR11");
	Unclickable_Object("PARKMETR15");
	Unclickable_Object("PARKMETR16");

	if (!Query_System_Currently_Loading_Game()) {
		Item_Add_To_World(kItemPS13Target1,  443, kSetPS10_PS11_PS12_PS13, -372.0f,   -9.0f,  1509.0f, 960, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS13Target2,  443, kSetPS10_PS11_PS12_PS13, 291.61f,  -0.66f,  1610.3f, 823, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS13Target3,  447, kSetPS10_PS11_PS12_PS13,  -25.0f,  102.0f,  1625.0f, 823, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS13Target4,  449, kSetPS10_PS11_PS12_PS13, -45.51f,   -8.8f,  1676.0f, 922, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS13Target5,  447, kSetPS10_PS11_PS12_PS13, 291.61f,  -0.66f,  1610.3f, 823, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS13Target6,  443, kSetPS10_PS11_PS12_PS13,  -24.0f,  102.0f,  1625.0f, 823, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS13Target7,  449, kSetPS10_PS11_PS12_PS13,  180.0f,  -72.7f,  1605.0f, 305, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS13Target8,  443, kSetPS10_PS11_PS12_PS13, 127.79f,  14.56f, 1703.03f, 356, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS13Target9,  443, kSetPS10_PS11_PS12_PS13, 136.37f,  -6.84f, 1425.43f, 512, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS13Target10, 441, kSetPS10_PS11_PS12_PS13,  77.83f,  -79.8f,  1520.5f, 327, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS13Target11, 441, kSetPS10_PS11_PS12_PS13,  77.83f,   -7.8f,  1520.5f, 327, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS13Target12, 443, kSetPS10_PS11_PS12_PS13,  -88.0f,   -8.8f,  1520.5f, 327, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS13Target13, 447, kSetPS10_PS11_PS12_PS13, -45.51f,   -8.8f,  1676.0f, 922, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS13Target14, 445, kSetPS10_PS11_PS12_PS13, -300.0f, -79.75f,  1543.0f, 465, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS13Target15, 449, kSetPS10_PS11_PS12_PS13, -325.0f,  -7.75f,  1543.0f, 465, 72, 36, true, false, false, true);
	}

	Police_Maze_Target_Track_Add(kItemPS13Target1,  -372.0f,   -9.0f,  1509.0f, -345.0f,   -9.0f,  1509.0f,  6, getPoliceMazePS13TrackData46(),  true);
	Police_Maze_Target_Track_Add(kItemPS13Target2,  291.61f,  -0.66f,  1610.3f, 238.83f,   1.03f, 1557.03f, 10, getPoliceMazePS13TrackData47(),  true);
	Police_Maze_Target_Track_Add(kItemPS13Target3,   -25.0f,  102.0f,  1625.0f,  -25.0f,  138.0f,  1625.0f, 10, getPoliceMazePS13TrackData48(),  true);
	Police_Maze_Target_Track_Add(kItemPS13Target4,  -45.51f,   -8.8f,  1676.0f,  15.51f,   -8.8f,  1679.0f, 10, getPoliceMazePS13TrackData49(), false);
	Police_Maze_Target_Track_Add(kItemPS13Target5,  291.61f,  -0.66f,  1610.3f, 238.83f,   1.03f, 1557.03f, 10, getPoliceMazePS13TrackData50(), false);
	Police_Maze_Target_Track_Add(kItemPS13Target6,   -24.0f,  102.0f,  1625.0f,  -24.0f,  138.0f,  1625.0f, 10, getPoliceMazePS13TrackData51(), false);
	Police_Maze_Target_Track_Add(kItemPS13Target7,   180.0f,  -72.7f,  1605.0f,  180.0f,   -0.7f,  1605.0f, 10, getPoliceMazePS13TrackData52(), false);
	Police_Maze_Target_Track_Add(kItemPS13Target8,  127.79f,  14.56f, 1703.03f, -56.07f,   1.89f, 1589.04f,  6, getPoliceMazePS13TrackData53(), false);
	Police_Maze_Target_Track_Add(kItemPS13Target9,  136.37f,  -6.84f, 1425.43f, 117.55f,  -6.84f, 1442.09f,  4, getPoliceMazePS13TrackData54(), false);
	Police_Maze_Target_Track_Add(kItemPS13Target10,  77.83f,  -79.8f,  1520.5f,  77.83f,   -7.8f,  1520.5f, 15, getPoliceMazePS13TrackData55(), false);
	Police_Maze_Target_Track_Add(kItemPS13Target11,  77.83f,   -7.8f,  1520.5f,  -88.0f,   -8.8f,  1520.5f, 15, getPoliceMazePS13TrackData56(), false);
	Police_Maze_Target_Track_Add(kItemPS13Target12,  -88.0f,   -8.8f,  1520.5f,  -88.0f,  -80.8f,  1520.5f, 15, getPoliceMazePS13TrackData57(), false);
	Police_Maze_Target_Track_Add(kItemPS13Target13, -45.51f,   -8.8f,  1676.0f,  15.51f,   -8.8f,  1679.0f, 10, getPoliceMazePS13TrackData58(),  true);
	Police_Maze_Target_Track_Add(kItemPS13Target14, -300.0f, -79.75f,  1543.0f, -300.0f, -14.75f,  1543.0f, 15, getPoliceMazePS13TrackData62(), false);
	Police_Maze_Target_Track_Add(kItemPS13Target15, -325.0f,  -7.75f,  1543.0f, -300.0f,  -7.75f,  1543.0f, 10, getPoliceMazePS13TrackData63(), false);
}

bool SceneScriptPS13::MouseClick(int x, int y) {
	return false;
}

bool SceneScriptPS13::ClickedOn3DObject(const char *objectName, bool a2) {
	return false;
}

bool SceneScriptPS13::ClickedOnActor(int actorId) {
	return false;
}

bool SceneScriptPS13::ClickedOnItem(int itemId, bool a2) {
	if (Player_Query_Combat_Mode()) {
		switch (itemId) {
		case kItemPS13Target3:
			Sound_Play(4, 50, 0, 0, 50);
			break;
		case kItemPS13Target5:
			Sound_Play(4, 50, 0, 0, 50);
			break;
		case kItemPS13Target10:
			Sound_Play(555, 50, 0, 0, 50);
			break;
		case kItemPS13Target11:
			Sound_Play(555, 50, 0, 0, 50);
			break;
		default:
			Sound_Play(2, 12, 0, 0, 50);
			break;
		}
		Item_Spin_In_World(itemId);
		Item_Flag_As_Non_Target(itemId);
		if (itemId == kItemPS13Target1) {
			Item_Flag_As_Non_Target(kItemPS13Target1);
		}
		if (itemId == kItemPS13Target2) {
			Item_Flag_As_Non_Target(kItemPS13Target2);
		}
		if (itemId == kItemPS13Target3) {
			Item_Flag_As_Non_Target(kItemPS13Target3);
		}
		if (itemId == kItemPS13Target4) {
			Item_Flag_As_Non_Target(kItemPS13Target4);
		}
		if (itemId == kItemPS13Target5) {
			Item_Flag_As_Non_Target(kItemPS13Target5);
		}
		if (itemId == kItemPS13Target6) {
			Item_Flag_As_Non_Target(kItemPS13Target6);
		}
		if (itemId == kItemPS13Target7) {
			Item_Flag_As_Non_Target(kItemPS13Target7);
		}
		if (itemId == kItemPS13Target8) {
			Item_Flag_As_Non_Target(kItemPS13Target8);
		}
		if (itemId == kItemPS13Target9) {
			Item_Flag_As_Non_Target(kItemPS13Target9);
		}
		if (itemId == kItemPS13Target10) {
			Item_Flag_As_Non_Target(kItemPS13Target10);
			Item_Flag_As_Non_Target(kItemPS13Target11);
			Item_Flag_As_Non_Target(kItemPS13Target12);
		}
		if (itemId == kItemPS13Target11) {
			Item_Flag_As_Non_Target(kItemPS13Target10);
			Item_Flag_As_Non_Target(kItemPS13Target11);
			Item_Flag_As_Non_Target(kItemPS13Target12);
		}
		if (itemId == kItemPS13Target12) {
			Item_Flag_As_Non_Target(kItemPS13Target10);
			Item_Flag_As_Non_Target(kItemPS13Target11);
			Item_Flag_As_Non_Target(kItemPS13Target12);
		}
		if (itemId == kItemPS13Target13) {
			Item_Flag_As_Non_Target(kItemPS13Target13);
		}
		if (itemId == kItemPS13Target14) {
			Item_Flag_As_Non_Target(kItemPS13Target14);
		}
		if (itemId == kItemPS13Target15) {
			Item_Flag_As_Non_Target(kItemPS13Target15);
		}
		return true;
	}
	return false;

}

bool SceneScriptPS13::ClickedOnExit(int exitId) {
	if (exitId == 0) {
		if (!Loop_Actor_Walk_To_Waypoint(kActorMcCoy, 10, 12, true, false)) {
			Game_Flag_Set(kFlagPS13toPS12);
			removeTargets();
			Set_Enter(kSetPS10_PS11_PS12_PS13, kScenePS12);
		}
		return true;
	}
	if (exitId == 1) {
		if (!Loop_Actor_Walk_To_Waypoint(kActorMcCoy, 11, 12, true, false)) {
			Game_Flag_Set(kFlagPS13toPS05);
			Player_Set_Combat_Mode(false);
			Ambient_Sounds_Remove_All_Non_Looping_Sounds(true);
			Ambient_Sounds_Remove_All_Looping_Sounds(1);
			removeTargets();
			Global_Variable_Decrement(kVariablePoliceMazeScore, kPoliceMazePS13TargetCount - Global_Variable_Query(kVariablePoliceMazePS13TargetCounter));
			Set_Score(kActorMcCoy, Global_Variable_Query(kVariablePoliceMazeScore));
			Global_Variable_Reset(kVariablePoliceMazePS10TargetCounter);
			Global_Variable_Reset(kVariablePoliceMazePS11TargetCounter);
			Global_Variable_Reset(kVariablePoliceMazePS12TargetCounter);
			Global_Variable_Reset(kVariablePoliceMazePS13TargetCounter);
			Global_Variable_Reset(kVariablePoliceMazeScore);
			Set_Enter(kSetPS05, kScenePS05);
		}
		return true;
	}
	return false;
}

bool SceneScriptPS13::ClickedOn2DRegion(int region) {
	return false;
}

void SceneScriptPS13::SceneFrameAdvanced(int frame) {
}

void SceneScriptPS13::ActorChangedGoal(int actorId, int newGoal, int oldGoal, bool currentSet) {
}

void SceneScriptPS13::PlayerWalkedIn() {
	Police_Maze_Set_Pause_State(false);
}

void SceneScriptPS13::PlayerWalkedOut() {
}

void SceneScriptPS13::DialogueQueueFlushed(int a1) {
}

void SceneScriptPS13::removeTargets() {
	Item_Remove_From_World(kItemPS13Target1);
	Item_Remove_From_World(kItemPS13Target2);
	Item_Remove_From_World(kItemPS13Target3);
	Item_Remove_From_World(kItemPS13Target4);
	Item_Remove_From_World(kItemPS13Target5);
	Item_Remove_From_World(kItemPS13Target6);
	Item_Remove_From_World(kItemPS13Target7);
	Item_Remove_From_World(kItemPS13Target8);
	Item_Remove_From_World(kItemPS13Target9);
	Item_Remove_From_World(kItemPS13Target10);
	Item_Remove_From_World(kItemPS13Target11);
	Item_Remove_From_World(kItemPS13Target12);
	Item_Remove_From_World(kItemPS13Target13);
	Item_Remove_From_World(kItemPS13Target14);
	Item_Remove_From_World(kItemPS13Target15);
}

} // End of namespace BladeRunner
