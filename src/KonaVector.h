
#ifndef KONAVECTOR_H
#define KONAVECTOR_H

#include "KonaPoint.h"

class KonaVector {

private:
    KonaPoint start;
    KonaPoint end;

public:
    KonaVector(KonaPoint start, KonaPoint end);
};

#endif /* KONAVECTOR_H */
