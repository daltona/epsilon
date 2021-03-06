#ifndef POINCARE_LAYOUT_ENGINE_H
#define POINCARE_LAYOUT_ENGINE_H

#include <poincare/expression.h>

namespace Poincare {

class LayoutEngine {
public:
  static ExpressionLayout * createInfixLayout(const Expression * expression, Expression::FloatDisplayMode floatDisplayMode, Expression::ComplexFormat complexFormat, const char * operatorName);
  static ExpressionLayout * createPrefixLayout(const Expression * expression, Expression::FloatDisplayMode floatDisplayMode, Expression::ComplexFormat complexFormat, const char * operatorName);

  static int writeInfixExpressionTextInBuffer(const Expression * expression, char * buffer, int bufferSize, const char * operatorName);
  static int writePrefixExpressionTextInBuffer(const Expression * expression, char * buffer, int bufferSize, const char * operatorName);
};

}

#endif
