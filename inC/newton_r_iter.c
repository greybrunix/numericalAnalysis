/* This is C89 code, as such i do not assure portability for C99 or above */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

#ifndef nan
#define nan  (double) 0xFF800001 + 1.f
#endif
#ifndef inf
#define inf (double) HUGE_VAL
#endif

struct uple
{ double res;
  int iter;
};
union Maybe
{ struct uple Just;
  int Nothing;
};

union Maybe
newton_method(
    double (*f)(double),
    double (*g)(double),
    double val,
    const double lim,
    const unsigned int max_iter)
{ struct uple resvalue;
  union Maybe res;
  double abs_change, deriv, fval;
  resvalue.res = 0.f; resvalue.iter = 0;
  res.Nothing = 0;
  abs_change = DBL_MAX;
  if (lim > 0.f)
  { do
    { deriv = (*g)(val); fval = (*f)(val);
      if (deriv == 0 || deriv == nan || deriv == inf
          || fval == nan || fval == inf) resvalue.res = nan;
      else
      { resvalue.res = val - (*f)(val) / (*g)(val);
        abs_change = fabs(resvalue.res - val);
        val = resvalue.res;
        resvalue.iter++;
      }
    } while (abs_change >= lim && resvalue.iter < max_iter && deriv != 0 &&
        deriv != nan && fval != nan && fval != inf && deriv != inf);
    if (resvalue.iter >= max_iter) resvalue.res = nan;
  }
  if (resvalue.res != nan) res.Just = resvalue;
  else res.Nothing = 1;
  return res;
}

double f(double x) {
  return x + 1.f;
}

double g(double x) {
  return 1.f;
}

int main() {
  double val = 0.f;
  const double lim = 1e-16;
  const unsigned int max_iter = 20;
  union Maybe res = newton_method(&f, &g, val, lim, max_iter);
  if (res.Nothing) {
    printf("No solution found\n");
  } else {
    printf("Solution found after %d iteration(s): %.4f\n", res.Just.iter, res.Just.res);
  }
  return 0;
}
