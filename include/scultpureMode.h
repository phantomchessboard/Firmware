#pragma once
#include "Arduino.h"
#include "FS.h"

void sculptureMain();

void centrarPiezasIniSc(int, char[10][10]);
void reorderChessboardPlus(int modo, char matrizObjetivoAux[10][10], char currentMatrix[10][10]);
int buscarPosicionCercanaVacia(int, int, char[10][10]);
int buscarPosicionCercanaPieza(int, int, char, char[10][10]);

void sensorsDir(void);
void updateSensors();
void readRawSensors(bool[10][10]);
void detectChessBoard(bool[10][10]);
void desfaseSensado();
int compareMatrixVsSensorsPlus(int, char [10][10]);

void setCurrentPosition(float pos1, float pos2);
String decodificaMovimiento(char, char, char, char, char, char, char [10][10], bool);
void movimientoSimplificado(int, int, int, int, char[10][10]);
int movementType(int escaqueFilaInit, int escaqueFilaEnd, int escaqueColInit, int escaqueColEnd);
float **generarTrayectoria(int coordXInit, int coordYInit, int coordXEnd, int coordYEnd, int &numPointsFinal);
float **interpolatePoints(float x1, float y1, float x2, float y2, int &numPoints);
void moveOnTheLinev2Sc(double, double, double, double, int &, double[][2]);
void puntosDeCurvaBezier(double, double, double, double, double, double, double *, double *, int);

void accelRampV3(float **trayectoriaFinal, int numPointsFinal, double speed);
void rawMovement(float filaEnd, float colEnd, int magnet, float &, float &);
void rawMovementStallGuard(float filaEnd, float colEnd, float speed, int modo, int &threshold, int &thresholdD2);
void configAndCurrentPosManager(int setSpeedbyUser, float &driverMicroSteps);
//void reInitVariables(void);
void activateElectromagnetV2(int optionElectro, int power);
void deactivateAllMagnets();
void calcularOffsets(int electroActivo, float &electroOffsetX, float &electroOffsetY);

void mechanicalCalibration(int calibType);


void sensorsCalibration(int filaEnd, int colEnd, int modo, float &totalX, float &totalY);
void configDrivers();
bool testDrivers();


void IRAM_ATTR moveRawStallGuard();
void IRAM_ATTR timeEnabled();

void printMatrizGenerica(char[][10], int, int);
String readFromFileSc(int);
//String decodeChessMove(char movChess[7][250], int cuentaMovimientos);
String decodeChessMove(char movChess[7], int cuentaMovimientos);
//void guardarMatriz(char[][10]);
//void leerMatriz(char[][10]);

void soundHandler(int);
//int batteryCheck(int mode);

void initMatrizPlus(char matrixToInit[10][10]);