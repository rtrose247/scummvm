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

static int kPoliceMazePS12TargetCount = 20;

void SceneScriptPS12::InitializeScene() {
	Police_Maze_Set_Pause_State(true);
	if (Game_Flag_Query(kFlagPS11toPS12)) {
		Scene_Loop_Start_Special(kSceneLoopModeLoseControl, 0, false);
		Scene_Loop_Set_Default(1);
		Setup_Scene_Information(World_Waypoint_Query_X(8), World_Waypoint_Query_Y(8), World_Waypoint_Query_Z(8), 512);
	} else {
		Scene_Loop_Set_Default(1);
		Setup_Scene_Information(World_Waypoint_Query_X(9), World_Waypoint_Query_Y(9), World_Waypoint_Query_Z(9), 0);
	}
	Scene_Exit_Add_2D_Exit(0, 0, 460, 639, 479, 2);
	Scene_Exit_Add_2D_Exit(1, 0,   5, 110, 196, 3);
}

static const int *getPoliceMazePS12TrackData29() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIObstacleReset,   kItemPS12Target1,
		kPMTIFacing,          200,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      4000, 10000,
		kPMTIObstacleSet,     kItemPS12Target1,
		kPMTIPlaySound,       33, 33,
		kPMTITargetSet,       kItemPS12Target1, 1,
		kPMTIEnemySet,        kItemPS12Target1,
		kPMTIMove,            5,
		kPMTIWait,            500,
		kPMTIShoot,           27, 33,
		kPMTIPlaySound,       34, 33,
		kPMTIMove,            0,
		kPMTIObstacleReset,   kItemPS12Target1,
		kPMTIPausedReset1of2, kItemPS12Target16, kItemPS12Target14,
		kPMTIPausedSet,       kItemPS12Target1,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS12TrackData30() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIObstacleReset,   kItemPS12Target2,
		kPMTIFacing,          67,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      3000, 9000,
		kPMTIObstacleSet,     kItemPS12Target2,
		kPMTIPlaySound,       33, 33,
		kPMTITargetSet,       kItemPS12Target2, 1,
		kPMTIEnemySet,        kItemPS12Target2,
		kPMTIMove,            5,
		kPMTIWait,            500,
		kPMTIShoot,           27, 33,
		kPMTIPlaySound,       34, 33,
		kPMTIMove,            0,
		kPMTIObstacleReset,   kItemPS12Target2,
		kPMTIPausedReset1of2, kItemPS12Target13, kItemPS12Target11,
		kPMTIPausedSet,       kItemPS12Target2,
		kPMTITargetSet,       kItemPS12Target2, 0,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS12TrackData31() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTITargetSet,       kItemPS12Target3, 1,
		kPMTIEnemyReset,      kItemPS12Target3,
		kPMTIObstacleReset,   kItemPS12Target3,
		kPMTIFacing,          480,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      3000, 10000,
		kPMTIObstacleSet,     kItemPS12Target3,
		kPMTIMove,            5,
		kPMTIPlaySound,       29, 33,
		kPMTIWait,            1000,
		kPMTIRotate,          968, 100,
		kPMTIPlaySound,       29, 33,
		kPMTIWait,            500,
		kPMTIMove,            0,
		kPMTIPlaySound,       29, 33,
		kPMTILeave,
		kPMTIObstacleReset,   kItemPS12Target3,
		kPMTIPausedReset1of3, kItemPS12Target12, kItemPS12Target4, kItemPS12Target5,
		kPMTIPausedSet,       kItemPS12Target3,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS12TrackData32() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIObstacleReset,   kItemPS12Target4,
		kPMTIFacing,          1010,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      3000, 10000,
		kPMTIObstacleSet,     kItemPS12Target4,
		kPMTIPlaySound,       33, 33,
		kPMTITargetSet,       kItemPS12Target4, 1,
		kPMTIEnemySet,        kItemPS12Target4,
		kPMTIMove,            5,
		kPMTIWait,            500,
		kPMTIShoot,           27, 33,
		kPMTIRotate,          498, 80,
		kPMTIPlaySound,       29, 33,
		kPMTIWait,            500,
		kPMTIMove,            0,
		kPMTIObstacleReset,   kItemPS12Target4,
		kPMTIPausedReset1of3, kItemPS12Target5, kItemPS12Target3, kItemPS12Target12,
		kPMTIPausedSet,       kItemPS12Target4,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS12TrackData33() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIObstacleReset,   kItemPS12Target5,
		kPMTIFacing,          540,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      4000, 10000,
		kPMTIObstacleSet,     kItemPS12Target5,
		kPMTITargetSet,       kItemPS12Target5, 1,
		kPMTIEnemyReset,      kItemPS12Target5,
		kPMTIMove,            5,
		kPMTIPlaySound,       29, 33,
		kPMTIWait,            1000,
		kPMTIRotate,          284, 80,
		kPMTIWait,            0,
		kPMTIRotate,          28, 80,
		kPMTIPlaySound,       29, 33,
		kPMTIWait,            1000,
		kPMTIMove,            0,
		kPMTILeave,
		kPMTIObstacleReset,   kItemPS12Target5,
		kPMTIPausedReset1of3, kItemPS12Target12, kItemPS12Target3, kItemPS12Target4,
		kPMTIPausedSet,       kItemPS12Target5,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS12TrackData34() {
	static int trackData[] = {
		kPMTIActivate,      kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIVariableInc,   kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIObstacleReset, kItemPS12Target6,
		kPMTIObstacleReset, kItemPS12Target7,
		kPMTIObstacleReset, kItemPS12Target8,
		kPMTIFacing,        469,
		kPMTIPosition,      0,
		kPMTITargetSet,     kItemPS12Target6, 1,
		kPMTITargetSet,     kItemPS12Target7, 1,
		kPMTITargetSet,     kItemPS12Target8, 1,
		kPMTIWaitRandom,    3000, 10000,
		kPMTIObstacleSet,   kItemPS12Target6,
		kPMTIEnemySet,      kItemPS12Target6,
		kPMTIEnemySet,      kItemPS12Target7,
		kPMTIEnemySet,      kItemPS12Target8,
		kPMTIMove,          5,
		kPMTIPlaySound,     29, 33,
		kPMTIWait,          1000,
		kPMTIRotate,        376, 80,
		kPMTIWait,          0,
		kPMTIRotate,        168, 80,
		kPMTIPlaySound,     29, 33,
		kPMTIMove,          9,
		kPMTIRotate,        33, 80,
		kPMTIWait,          0,
		kPMTIRotate,        15, 80,
		kPMTIPlaySound,     29, 33,
		kPMTIWait,          500,
		kPMTIShoot,         27, 33,
		kPMTIMove,          5,
		kPMTIPlaySound,     29, 33,
		kPMTIRotate,        168, 80,
		kPMTIWait,          0,
		kPMTIRotate,        376, 80,
		kPMTIWait,          0,
		kPMTIRotate,        469, 80,
		kPMTIPlaySound,     29, 33,
		kPMTIWait,          500,
		kPMTITargetSet,     kItemPS12Target6, 1,
		kPMTITargetSet,     kItemPS12Target7, 1,
		kPMTITargetSet,     kItemPS12Target8, 1,
		kPMTIEnemySet,      kItemPS12Target6,
		kPMTIEnemySet,      kItemPS12Target7,
		kPMTIEnemySet,      kItemPS12Target8,
		kPMTIRotate,        376, 80,
		kPMTIWait,          0,
		kPMTIRotate,        168, 80,
		kPMTIMove,          9,
		kPMTIRotate,        33, 80,
		kPMTIWait,          0,
		kPMTIRotate,        15, 80,
		kPMTIPlaySound,     29, 33,
		kPMTIWait,          500,
		kPMTIShoot,         27, 33,
		kPMTIMove,          5,
		kPMTIPlaySound,     29, 33,
		kPMTIWait,          0,
		kPMTIRotate,        469, 80,
		kPMTIWait,          500,
		kPMTIRotate,        198, 80,
		kPMTIPlaySound,     29, 33,
		kPMTIWait,          0,
		kPMTIMove,          19,
		kPMTIPlaySound,     29, 33,
		kPMTIWait,          0,
		kPMTIObstacleReset, kItemPS12Target6,
		kPMTIPausedReset,   kItemPS12Target7,
		kPMTIPausedSet,     kItemPS12Target6,
		kPMTIPosition,      0,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS12TrackData35() {
	static int trackData[] = {
		kPMTIObstacleSet,   kItemPS12Target7,
		kPMTIFacing,        198,
		kPMTIPosition,      0,
		kPMTIRotate,        469, 80,
		kPMTIMove,          9,
		kPMTIWait,          0,
		kPMTIObstacleReset, kItemPS12Target7,
		kPMTIPausedReset,   kItemPS12Target8,
		kPMTIPausedSet,     kItemPS12Target7,
		kPMTIFacing,        198,
		kPMTIObstacleSet,   kItemPS12Target7,
		kPMTIPosition,      0,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS12TrackData36() {
	static int trackData[] = {
		kPMTIObstacleSet,   kItemPS12Target8,
		kPMTIFacing,        469,
		kPMTIPosition,      0,
		kPMTIObstacleSet,   kItemPS12Target8,
		kPMTIMove,          9,
		kPMTIPlaySound,     29, 33,
		kPMTIWait,          1000,
		kPMTIObstacleReset, kItemPS12Target6,
		kPMTIObstacleReset, kItemPS12Target7,
		kPMTIObstacleReset, kItemPS12Target8,
		kPMTIPausedReset,   kItemPS12Target9,
		kPMTIPausedSet,     kItemPS12Target8,
		kPMTIFacing,        469,
		kPMTIObstacleSet,   kItemPS12Target8,
		kPMTIPosition,      0,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS12TrackData37() {
	static int trackData[] = {
		kPMTIActivate,      kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIVariableInc,   kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIObstacleReset, kItemPS12Target9,
		kPMTIWaitRandom,    3000, 6000,
		kPMTIPausedReset,   kItemPS12Target10,
		kPMTIFacing,        1010,
		kPMTIPosition,      0,
		kPMTIWait,          2000,
		kPMTIObstacleSet,   kItemPS12Target9,
		kPMTIPlaySound,     33, 33,
		kPMTITargetSet,     kItemPS12Target9, 1,
		kPMTIEnemyReset,    kItemPS12Target9,
		kPMTIMove,          9,
		kPMTIWait,          3000,
		kPMTIPlaySound,     34, 33,
		kPMTIMove,          0,
		kPMTILeave,
		kPMTIObstacleReset, kItemPS12Target9,
		kPMTIPausedSet,     kItemPS12Target9,
		kPMTIPosition,      0,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS12TrackData38() {
	static int trackData[] = {
		kPMTIObstacleReset, kItemPS12Target10,
		kPMTIFacing,        990,
		kPMTIPosition,      0,
		kPMTIWait,          3000,
		kPMTIObstacleSet,   kItemPS12Target10,
		kPMTIPlaySound,     33, 33,
		kPMTITargetSet,     kItemPS12Target10, 1,
		kPMTIEnemySet,      kItemPS12Target10,
		kPMTIMove,          9,
		kPMTIWait,          1000,
		kPMTIShoot,         12, 33,
		kPMTIPlaySound,     34, 33,
		kPMTIMove,          0,
		kPMTIObstacleReset, kItemPS12Target10,
		kPMTIPausedReset,   kItemPS12Target6,
		kPMTIPausedSet,     kItemPS12Target10,
		kPMTIPosition,      0,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS12TrackData39() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIObstacleReset,   kItemPS12Target11,
		kPMTIFacing,          513,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      5000, 5000,
		kPMTIObstacleSet,     kItemPS12Target11,
		kPMTIPlaySound,       33, 33,
		kPMTITargetSet,       kItemPS12Target11, 1,
		kPMTIMove,            5,
		kPMTIWait,            1000,
		kPMTIEnemySet,        kItemPS12Target11,
		kPMTIRotate,          1010, 80,
		kPMTIPlaySound,       29, 33,
		kPMTIWait,            500,
		kPMTIShoot,           27, 33,
		kPMTIPlaySound,       34, 33,
		kPMTIMove,            0,
		kPMTIObstacleReset,   kItemPS12Target11,
		kPMTIPausedReset1of2, kItemPS12Target13, kItemPS12Target2,
		kPMTIPausedSet,       kItemPS12Target11,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS12TrackData40() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIObstacleReset,   kItemPS12Target12,
		kPMTIFacing,          480,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      4000, 8000,
		kPMTIObstacleSet,     kItemPS12Target12,
		kPMTIPlaySound,       29, 33,
		kPMTITargetSet,       kItemPS12Target12, 1,
		kPMTIMove,            5,
		kPMTIPlaySound,       29, 33,
		kPMTIWait,            500,
		kPMTIEnemySet,        kItemPS12Target12,
		kPMTIRotate,          968, 80,
		kPMTIPlaySound,       29, 33,
		kPMTIWait,            1000,
		kPMTIShoot,           27, 33,
		kPMTIMove,            0,
		kPMTIObstacleReset,   kItemPS12Target12,
		kPMTIPausedReset1of3, kItemPS12Target3, kItemPS12Target4, kItemPS12Target5,
		kPMTIPausedSet,       kItemPS12Target12,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS12TrackData41() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIObstacleReset,   kItemPS12Target13,
		kPMTIFacing,          513,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      4000, 6000,
		kPMTIObstacleSet,     kItemPS12Target13,
		kPMTIPlaySound,       33, 33,
		kPMTITargetSet,       kItemPS12Target13, 1,
		kPMTIEnemyReset,      kItemPS12Target13,
		kPMTIMove,            5,
		kPMTIWait,            500,
		kPMTIRotate,          1010, 80,
		kPMTIPlaySound,       29, 33,
		kPMTIWait,            1000,
		kPMTIMove,            0,
		kPMTIPlaySound,       34, 33,
		kPMTILeave,
		kPMTIObstacleReset,   kItemPS12Target13,
		kPMTIPausedReset1of2, kItemPS12Target11, kItemPS12Target2,
		kPMTIPausedSet,       kItemPS12Target13,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS12TrackData42() {
	static int trackData[] = {
		kPMTIObstacleReset,   kItemPS12Target14,
		kPMTIFacing,          109,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      2000, 5000,
		kPMTIObstacleSet,     kItemPS12Target14,
		kPMTIPlaySound,       29, 33,
		kPMTITargetSet,       kItemPS12Target14, 1,
		kPMTIEnemySet,        kItemPS12Target14,
		kPMTIMove,            5,
		kPMTIPlaySound,       29, 33,
		kPMTIWait,            1000,
		kPMTIShoot,           27, 33,
		kPMTIMove,            0,
		kPMTIObstacleReset,   kItemPS12Target14,
		kPMTIPausedReset1of2, kItemPS12Target16, kItemPS12Target1,
		kPMTIPausedSet,       kItemPS12Target14,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS12TrackData43() {
	static int trackData[] = {
		kPMTIActivate,      kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIVariableInc,   kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIObstacleReset, kItemPS12Target15,
		kPMTIFacing,        540,
		kPMTIPosition,      0,
		kPMTIWaitRandom,    5000, 7000,
		kPMTIObstacleSet,   kItemPS12Target15,
		kPMTIPlaySound,     33, 33,
		kPMTITargetSet,     kItemPS12Target15, 1,
		kPMTIEnemyReset,    kItemPS12Target15,
		kPMTIMove,          9,
		kPMTIWait,          2000,
		kPMTIRotate,        284, 80,
		kPMTIWait,          0,
		kPMTIRotate,        28, 80,
		kPMTIPlaySound,     29, 33,
		kPMTIWait,          2000,
		kPMTIPlaySound,     34, 33,
		kPMTIMove,          0,
		kPMTILeave,
		kPMTIObstacleReset, kItemPS12Target15,
		kPMTIPausedReset,   kItemPS12Target17,
		kPMTIPausedSet,     kItemPS12Target15,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS12TrackData44() {
	static int trackData[] = {
		kPMTIActivate,        kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIVariableInc,     kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIObstacleReset,   kItemPS12Target16,
		kPMTIFacing,          109,
		kPMTIPosition,        0,
		kPMTIWaitRandom,      5000, 5000,
		kPMTIObstacleSet,     kItemPS12Target16,
		kPMTIPlaySound,       29, 33,
		kPMTITargetSet,       kItemPS12Target16, 1,
		kPMTIEnemyReset,      kItemPS12Target16,
		kPMTIMove,            5,
		kPMTIWaitRandom,      2000, 2000,
		kPMTIPlaySound,       29, 33,
		kPMTIMove,            0,
		kPMTILeave,
		kPMTIObstacleReset,   kItemPS12Target16,
		kPMTIPausedReset1of2, kItemPS12Target14, kItemPS12Target1,
		kPMTIPausedSet,       kItemPS12Target16,
		kPMTIRestart
	};
	return trackData;
}

static const int *getPoliceMazePS12TrackData45() {
	static int trackData[] = {
		kPMTIActivate,      kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIVariableInc,   kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount,
		kPMTIObstacleReset, kItemPS12Target17,
		kPMTIFacing,        540,
		kPMTIPosition,      0,
		kPMTIWaitRandom,    3000, 10000,
		kPMTIObstacleSet,   kItemPS12Target17,
		kPMTIPlaySound,     33, 33,
		kPMTITargetSet,     kItemPS12Target17, 1,
		kPMTIMove,          9,
		kPMTIWait,          1000,
		kPMTIEnemySet,      kItemPS12Target17,
		kPMTIRotate,        284, 80,
		kPMTIWait,          0,
		kPMTIRotate,        28, 80,
		kPMTIWait,          1000,
		kPMTIShoot,         27, 33,
		kPMTIPlaySound,     34, 33,
		kPMTIMove,          0,
		kPMTIObstacleReset, kItemPS12Target17,
		kPMTIPausedReset,   kItemPS12Target15,
		kPMTIPausedSet,     kItemPS12Target17,
		kPMTIRestart
	};
	return trackData;
}

void SceneScriptPS12::SceneLoaded() {
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
		Item_Add_To_World(kItemPS12Target1,  449, kSetPS10_PS11_PS12_PS13,  -691.8f, -9.06f, 587.67f,  200, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS12Target2,  445, kSetPS10_PS11_PS12_PS13,  -679.6f, -45.4f, 721.05f,   67, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS12Target3,  447, kSetPS10_PS11_PS12_PS13, -414.04f, -8.98f, 711.91f,  480, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS12Target4,  443, kSetPS10_PS11_PS12_PS13,  -440.0f, -8.97f, 1137.0f, 1010, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS12Target5,  441, kSetPS10_PS11_PS12_PS13, -764.92f, -0.84f, 950.22f,  540, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS12Target6,  449, kSetPS10_PS11_PS12_PS13,  -696.0f,  -5.7f, 1185.0f,  469, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS12Target7,  449, kSetPS10_PS11_PS12_PS13,  -635.0f,  -5.7f, 1165.0f,  198, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS12Target8,  449, kSetPS10_PS11_PS12_PS13,  -620.0f, -8.63f, 1366.0f,  469, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS12Target9,  447, kSetPS10_PS11_PS12_PS13,  -584.0f, -79.4f,  775.0f, 1010, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS12Target10, 445, kSetPS10_PS11_PS12_PS13,  -578.0f, -79.4f,  810.0f,  990, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS12Target11, 443, kSetPS10_PS11_PS12_PS13,  -400.0f, -12.0f, 1110.0f,  513, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS12Target12, 449, kSetPS10_PS11_PS12_PS13, -414.04f, -8.98f, 711.91f,  480, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS12Target13, 447, kSetPS10_PS11_PS12_PS13,  -400.0f, -12.0f, 1110.0f,  513, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS12Target14, 449, kSetPS10_PS11_PS12_PS13,  -731.0f, 93.66f,  788.0f,  109, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS12Target15, 441, kSetPS10_PS11_PS12_PS13,  -580.0f, -80.0f,  925.0f,  540, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS12Target16, 441, kSetPS10_PS11_PS12_PS13,  -731.0f, 93.66f,  788.0f,  109, 72, 36, true, false, false, true);
		Item_Add_To_World(kItemPS12Target17, 443, kSetPS10_PS11_PS12_PS13,  -580.0f, -80.0f,  925.0f,  540, 72, 36, true, false, false, true);
	}
	Police_Maze_Target_Track_Add(kItemPS12Target1,   -691.8f, -9.06f, 587.67f, -649.11f, -9.06f, 587.71f,  6, getPoliceMazePS12TrackData29(),  true);
	Police_Maze_Target_Track_Add(kItemPS12Target2,   -679.6f, -45.4f, 721.05f,  -679.6f,  -1.4f, 721.05f,  6, getPoliceMazePS12TrackData30(),  true);
	Police_Maze_Target_Track_Add(kItemPS12Target3,  -414.04f, -8.98f, 711.91f, -459.54f, -8.99f, 707.81f,  6, getPoliceMazePS12TrackData31(), false);
	Police_Maze_Target_Track_Add(kItemPS12Target4,   -440.0f, -8.97f, 1137.0f,  -430.0f, -8.97f,  921.0f,  6, getPoliceMazePS12TrackData32(), false);
	Police_Maze_Target_Track_Add(kItemPS12Target5,  -764.92f, -0.84f, 950.22f, -722.92f, -0.84f, 950.22f,  6, getPoliceMazePS12TrackData33(), false);
	Police_Maze_Target_Track_Add(kItemPS12Target6,   -696.0f,  -5.7f, 1185.0f,  -635.0f,  -5.7f, 1185.0f, 20, getPoliceMazePS12TrackData34(), false);
	Police_Maze_Target_Track_Add(kItemPS12Target7,   -635.0f,  -5.7f, 1165.0f,  -620.0f, -8.63f, 1366.0f, 10, getPoliceMazePS12TrackData35(), false);
	Police_Maze_Target_Track_Add(kItemPS12Target8,   -620.0f, -8.63f, 1366.0f,  -595.0f, -8.63f, 1366.0f, 10, getPoliceMazePS12TrackData36(), false);
	Police_Maze_Target_Track_Add(kItemPS12Target9,   -584.0f, -79.4f,  775.0f,  -584.0f, -27.4f,  775.0f, 10, getPoliceMazePS12TrackData37(),  true);
	Police_Maze_Target_Track_Add(kItemPS12Target10,  -578.0f, -79.4f,  810.0f,  -578.0f, -27.4f,  810.0f, 10, getPoliceMazePS12TrackData38(), false);
	Police_Maze_Target_Track_Add(kItemPS12Target11,  -400.0f, -12.0f, 1110.0f,  -400.0f,  60.0f, 1110.0f,  6, getPoliceMazePS12TrackData39(), false);
	Police_Maze_Target_Track_Add(kItemPS12Target12, -414.04f, -8.98f, 711.91f, -459.54f, -8.99f, 707.81f,  6, getPoliceMazePS12TrackData40(),  true);
	Police_Maze_Target_Track_Add(kItemPS12Target13,  -400.0f, -12.0f, 1110.0f,  -400.0f,  60.0f, 1110.0f,  6, getPoliceMazePS12TrackData41(), false);
	Police_Maze_Target_Track_Add(kItemPS12Target14,  -731.0f, 93.66f,  788.0f,  -702.0f, 93.66f,  788.0f,  6, getPoliceMazePS12TrackData42(), false);
	Police_Maze_Target_Track_Add(kItemPS12Target15,  -580.0f, -80.0f,  925.0f,  -580.0f,  -8.0f,  925.0f, 10, getPoliceMazePS12TrackData43(),  true);
	Police_Maze_Target_Track_Add(kItemPS12Target16,  -731.0f, 93.66f,  788.0f,  -702.0f, 93.66f,  788.0f,  6, getPoliceMazePS12TrackData44(), false);
	Police_Maze_Target_Track_Add(kItemPS12Target17,  -580.0f, -80.0f,  925.0f,  -580.0f,  -8.0f,  925.0f, 10, getPoliceMazePS12TrackData45(), false);

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

bool SceneScriptPS12::MouseClick(int x, int y) {
	return false;
}

bool SceneScriptPS12::ClickedOn3DObject(const char *objectName, bool a2) {
	return false;
}

bool SceneScriptPS12::ClickedOnActor(int actorId) {
	return false;
}

bool SceneScriptPS12::ClickedOnItem(int itemId, bool a2) {
	if (Player_Query_Combat_Mode()) {
		switch (itemId) {
		case kItemPS12Target3:
			Sound_Play(4, 50, 0, 0, 50);
			break;
		case kItemPS12Target5:
			Sound_Play(555, 50, 0, 0, 50);
			break;
		case kItemPS12Target9:
			Sound_Play(4, 50, 0, 0, 50);
			break;
		case kItemPS12Target13:
			Sound_Play(4, 50, 0, 0, 50);
			break;
		case kItemPS12Target15:
			Sound_Play(555, 50, 0, 0, 50);
			break;
		case kItemPS12Target16:
			Sound_Play(555, 50, 0, 0, 50);
			break;
		default:
			Sound_Play(2, 12, 0, 0, 50);
			break;
		}
		Item_Spin_In_World(itemId);
		Item_Flag_As_Non_Target(itemId);
		if (itemId == kItemPS12Target1) {
			Item_Flag_As_Non_Target(kItemPS12Target1);
		}
		if (itemId == kItemPS12Target2) {
			Item_Flag_As_Non_Target(kItemPS12Target2);
		}
		if (itemId == kItemPS12Target3) {
			Item_Flag_As_Non_Target(kItemPS12Target3);
		}
		if (itemId == kItemPS12Target4) {
			Item_Flag_As_Non_Target(kItemPS12Target4);
		}
		if (itemId == kItemPS12Target5) {
			Item_Flag_As_Non_Target(kItemPS12Target5);
		}
		if (itemId == kItemPS12Target6) {
			Item_Flag_As_Non_Target(kItemPS12Target6);
			Item_Flag_As_Non_Target(kItemPS12Target7);
			Item_Flag_As_Non_Target(kItemPS12Target8);
		}
		if (itemId == kItemPS12Target7) {
			Item_Flag_As_Non_Target(kItemPS12Target6);
			Item_Flag_As_Non_Target(kItemPS12Target7);
			Item_Flag_As_Non_Target(kItemPS12Target8);
		}
		if (itemId == kItemPS12Target8) {
			Item_Flag_As_Non_Target(kItemPS12Target6);
			Item_Flag_As_Non_Target(kItemPS12Target7);
			Item_Flag_As_Non_Target(kItemPS12Target8);
		}
		if (itemId == kItemPS12Target9) {
			Item_Flag_As_Non_Target(kItemPS12Target9);
		}
		if (itemId == kItemPS12Target10) {
			Item_Flag_As_Non_Target(kItemPS12Target10);
		}
		if (itemId == kItemPS12Target11) {
			Item_Flag_As_Non_Target(kItemPS12Target11);
		}
		if (itemId == kItemPS12Target12) {
			Item_Flag_As_Non_Target(kItemPS12Target12);
		}
		if (itemId == kItemPS12Target13) {
			Item_Flag_As_Non_Target(kItemPS12Target13);
		}
		if (itemId == kItemPS12Target14) {
			Item_Flag_As_Non_Target(kItemPS12Target14);
		}
		if (itemId == kItemPS12Target15) {
			Item_Flag_As_Non_Target(kItemPS12Target15);
		}
		if (itemId == kItemPS12Target16) {
			Item_Flag_As_Non_Target(kItemPS12Target16);
		}
		if (itemId == kItemPS12Target17) {
			Item_Flag_As_Non_Target(kItemPS12Target17);
		}
		return true;
	}
	return false;
}

bool SceneScriptPS12::ClickedOnExit(int exitId) {
	if (exitId == 0) {
		if (!Loop_Actor_Walk_To_Waypoint(kActorMcCoy, 8, 12, true, false)) {
			Game_Flag_Set(kFlagPS12toPS11);
			removeTargets();
			Set_Enter(kSetPS10_PS11_PS12_PS13, kScenePS11);
		}
		return true;
	}
	if (exitId == 1) {
		if (!Loop_Actor_Walk_To_Waypoint(kActorMcCoy, 9, 12, true, false)) {
			Player_Loses_Control();
			Loop_Actor_Walk_To_Waypoint(kActorMcCoy, 10, 12, false, false);
			Player_Gains_Control();
			Game_Flag_Set(kFlagPS12toPS13);
			removeTargets();
			Global_Variable_Decrement(kVariablePoliceMazeScore, kPoliceMazePS12TargetCount - Global_Variable_Query(kVariablePoliceMazePS12TargetCounter));
			Global_Variable_Set(kVariablePoliceMazePS12TargetCounter, kPoliceMazePS12TargetCount);
			Set_Enter(kSetPS10_PS11_PS12_PS13, kScenePS13);
		}
		return true;
	}
	return false;
}

bool SceneScriptPS12::ClickedOn2DRegion(int region) {
	return false;
}

void SceneScriptPS12::SceneFrameAdvanced(int frame) {
}

void SceneScriptPS12::ActorChangedGoal(int actorId, int newGoal, int oldGoal, bool currentSet) {
}

void SceneScriptPS12::PlayerWalkedIn() {
	if (Game_Flag_Query(kFlagPS11toPS12)) {
		Loop_Actor_Walk_To_XYZ(kActorMcCoy, -546.0f, -9.06f, 570.0f, 0, true, false, 0);
		Game_Flag_Reset(kFlagPS11toPS12);
	}
	Police_Maze_Set_Pause_State(false);
}

void SceneScriptPS12::PlayerWalkedOut() {
}

void SceneScriptPS12::DialogueQueueFlushed(int a1) {
}

void SceneScriptPS12::removeTargets() {
	Item_Remove_From_World(kItemPS12Target1);
	Item_Remove_From_World(kItemPS12Target2);
	Item_Remove_From_World(kItemPS12Target3);
	Item_Remove_From_World(kItemPS12Target4);
	Item_Remove_From_World(kItemPS12Target5);
	Item_Remove_From_World(kItemPS12Target6);
	Item_Remove_From_World(kItemPS12Target7);
	Item_Remove_From_World(kItemPS12Target8);
	Item_Remove_From_World(kItemPS12Target9);
	Item_Remove_From_World(kItemPS12Target10);
	Item_Remove_From_World(kItemPS12Target11);
	Item_Remove_From_World(kItemPS12Target12);
	Item_Remove_From_World(kItemPS12Target13);
	Item_Remove_From_World(kItemPS12Target14);
	Item_Remove_From_World(kItemPS12Target15);
	Item_Remove_From_World(kItemPS12Target16);
	Item_Remove_From_World(kItemPS12Target17);
}

} // End of namespace BladeRunner
