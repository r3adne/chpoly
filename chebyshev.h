//
// Created by ariadne on 7/18/24.
//


#ifndef CHPOLY_CHEBYSHEV_H
#define CHPOLY_CHEBYSHEV_H

#include <juce_core/juce_core.h>
#include <juce_audio_basics/juce_audio_basics.h>

struct chebyshev
{
    template <class T>
    static T chIexplicit(T x, int n)
    {
        T xx = x*x;
        T sqrtxxminus1 = sqrt<T>(xx - 1);
        T xminsqrt = (x - sqrtxxminus1);
        T a = pow(xminsqrt, n);
        T b = pow(xminsqrt, -n);
        return (T) 0.5 * (a + b);
    }

    template <class T>
    static T chIrecursive(T x, int n)
    {
        if (n == 0) return static_cast<T>(1);
        else if (n == 1) return static_cast<T>(x);

        return chIrecursive(x, n-1) - chIrecursive(x, n-2);
    }
};



#endif //CHPOLY_CHEBYSHEV_H
