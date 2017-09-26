# coding: utf-8

# ---- Imports ----

# Libraries to be used.
import sys
sys.path.append("../include")
sys.path.append("../src")

# The standard libraries used in the visual memory system.

# Used class developed by RoboFEI-HT.
from BasicThread import * # Responsible for implementing the methods and variables responsible for managing the thread.

## Class to Robots
# Class responsible for performing robots tracking.
class Robots(BasicThread):
    
    # ---- Variables ----
    
    ## listfunction
    # .
    __listfunction = None
    
    ## robotnumber
    # .
    __robotnumber = None
    
    ## posdata
    # .
    __posdata = None
    
    ## __lastposdata
    # .
    __lastposdata = None
    
    ## timenumber
    # .
    timenumber = 0
    
    ## weight
    # .
    weight = 0
    
    ## reset
    # .
    def reset(self):
        super(Robots, self)._reset( )
        
        self._A = self._A[:-2,:-2]
        self._B = self._B[:-2,:]
        self._R = self._R[:-2,:-2]
        self._C = self._C[:,:-2]
        
        self._predictedstate["x"] = self._predictedstate["x"][:-2,:]
        self._predictedstate["covariance"] = self._predictedstate["covariance"][:-2,:-2]
    
    ## Constructor Class
    def __init__(self, s, pos):
        # Instantiating constructor for inherited class.
        super(Robots, self).__init__(s, "Robots")
        
        self.__posdata = pos
        
        # Creating characteristic variables for Robots and reading.
        self._parameters.update({ })
        self._parameters = self._conf.readVariables(self._parameters)
        
        self.reset( )
        
        self.__listfunction = [ ]
        
        self.start( )
        
    ## __predictVector
    # .
    def __predictVector(self, vector):
        tnow, movements = vector
        super(Robots, self).self.predict(tnow, movements)
        
        if tnow == None and __time__robotnumber != 0:
            if __time__robotnumber == 1:
                self._bkb.write_float(
                    "VISUAL_MEMORY_AL_" + str(self.__robotnumber).zfill(2) + "_X",
                    self._state["x"][0]
                )
                self._bkb.write_float(
                    "VISUAL_MEMORY_AL_" + str(self.__robotnumber).zfill(2) + "_Y",
                    self._state["x"][1]
                )
                
                if sym.sqrt(self._state["x"][2]**2 + self._state["x"][3]**2) > self._bkb.read_float("VISUAL_MEMORY_AL_" + str(self.__robotnumber).zfill(2) + "_MAX_VEL"):
                    self._bkb.write_float(
                        "VISUAL_MEMORY_AL_" + str(self.__robotnumber).zfill(2) + "_MAX_VEL",
                        sym.sqrt(self._state["x"][2]**2 + self._state["x"][3]**2)
                    )
            else:
                self._bkb.write_float(
                    "VISUAL_MEMORY_OP_" + str(self.__robotnumber).zfill(2) + "_X",
                    self._state["x"][0]
                )
                self._bkb.write_float(
                    "VISUAL_MEMORY_OP_" + str(self.__robotnumber).zfill(2) + "_Y",
                    self._state["x"][1]
                )
                
                if sym.sqrt(self._state["x"][2]**2 + self._state["x"][3]**2) > self._bkb.read_float("VISUAL_MEMORY_AL_" + str(self.__robotnumber).zfill(2) + "_MAX_VEL"):
                    self._bkb.write_float(
                        "VISUAL_MEMORY_OP_" + str(self.__robotnumber).zfill(2) + "_MAX_VEL",
                        sym.sqrt(self._state["x"][2]**2 + self._state["x"][3]**2)
                    )
    
    ## predictThread
    # .
    def predictThread(self, tnow = None, movements = None):
        self.__listfunction.append([self.__predictVector, [tnow, movements]])
        self._resume( )
    
    ## updateVector
    # .
    def __updateVector(self, data):
        if data["tag"] != 0:
            self.timenumber = data["tag"]
        
        super(Robots, self).update(data)
    
    ## updateThread
    # .
    def updateThread(self, data):
        self.__listfunction.append([self.__updateVector, data])
        self._resume( )
    
    ## run
    # .
    def run(self):
        self._running = True
        while self._running:
            with self._pausethread:
                while self.__listfunction != []:
                    func, data = self.__listfunction.pop(0)
                    func(data)
            self._pause( )
    
    ## end
    # .
    def end(self):
        self.__listfunction = [ ]
        self._finalize( )
        super(Robots, self)._end( )
    
    ## calculatesDistance
    # .
    def calculatesDistance(self):
        if self.__lastposdata == self.__posdata:
            return
        
        self.__lastposdata = copy(self.__posdata)
        
        self.weight = sym.exp(
            -0.5*sym.transpose(sym.Matrix(self.__posdata) - self.state["x"][:2,:2])*
            self.state["covariance"][:2,:2]*
            (sym.Matrix(self.__posdata) - self.state["x"][:2,:2])
        )[0]
    
    ## __lt__
    # .
    def __lt__(self, other):
        self.calculatesDistance( )
        other.calculatesDistance( )
        return self.weight < other.weight