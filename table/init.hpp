/*!	
	\file   init.hpp
	\brief   Prototype of the function for the initialization of table of symbols
	\author  
	\date    2017-12-5
	\version 1.0
*/

#ifndef _INIT_HPP_
#define _INIT_HPP_

// sin, cos, atan, fabs, ...
#include <math.h>

#include "table.hpp"

// IMPORTANT: This file must be before y.tab.h
#include "../ast/ast.hpp"
///////////////////////////////////////

//  interpreter.tab.h contains the number values of the tokens produced by the parser
#include "../parser/interpreter.tab.h"

///////////////////////////////////////
// NEW in example 13
#include "mathFunction.hpp"
#include "builtinParameter1.hpp"
///////////////////////////////////////

///////////////////////////////////////
// NEW in example 14
#include "builtinParameter0.hpp"
#include "builtinParameter2.hpp"
///////////////////////////////////////

/*!
  \ brief Predefined numeric constants
*/
static struct {
          std::string name ;
	      double value;
	      } numericConstant[] = {
	                    {"PI",    3.14159265358979323846},
	                    {"E",     2.71828182845904523536},
	                    {"GAMMA", 0.57721566490153286060},
	                    {"DEG",  57.29577951308232087680},
	                    {"PHI",   1.61803398874989484820},
	                    {"",      0}
	                   };

/*!
  \ brief Predefined logical constants
*/
// NEW in example 16
static struct {
          std::string name ;
	      bool value;
	      } logicalConstant[] = { 
	                    {"verdadero", true},
	                    {"falso", false},
	                    {"",      0}
	                   };


// NEW in example 12 
/*!
  \ brief Predefined keywords
*/
static struct {
          std::string name ;
	      int token;
	      } keyword[] = { 
	                    {"escribir", PRINT},
	                    {"escribir_cadena", PRINT},
	                    {"leer",  READ},
	                    {"leer_cadena",  READ},
						{"si",	  IF},   	// NEW in example 17
						{"entonces",	  THEN},   	// NEW in example 17
						{"si_no",  ELSE}, 	// NEW in example 17
						{"fin_si",  ENDIF}, 	// NEW in example 17
						{"mientras", WHILE},	// NEW in example 17
						{"hacer", DO},	// NEW in example 17
						{"fin_mientras", ENDWHILE},	// NEW in example 17
						{"repetir", REPEAT},	// NEW in example 17
						{"hasta", TILL},	// NEW in example 17
	                    {"",      0}
	                   };



// NEW in example 13

static struct {    /* Predefined functions names */ 
                std::string name ;
				lp::TypePointerDoubleFunction_1 function;
              } function_1 [] = {
	                   {"sin",     sin},
		               {"cos",     cos},
		               {"atan",    atan},
		               {"log",     Log},
		               {"log10",   Log10},
		               {"exp",     Exp},
		               {"sqrt",    Sqrt},
		               {"integer", integer},
		               {"abs",     fabs},   
		               {"",       0}
		              };

// NEW in example 14
static struct {   
                std::string name ;
				lp::TypePointerDoubleFunction_0 function;
              } function_0 [] = {
						{"random", Random},
		                {"",       0}
		              };


// NEW in example 14

static struct {    /* Nombres predefinidos de funciones con 2 argumentos */ 
                std::string name ;
				lp::TypePointerDoubleFunction_2 function;
              } function_2 [] = {
	                   {"atan2",   Atan2},
		               {"",       0}
		              };







/*!		
	\brief   Initialize the table of symbols
	\return  void 
*/

void init(lp::Table &t);

// End of _INIT_HPP_
#endif
