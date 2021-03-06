//
// Created by Michael Heuer on 10.03.18.
//

#ifndef SPHERICALSURFACEINTEGRATOR_H
#define SPHERICALSURFACEINTEGRATOR_H

#include "SpatialFunction.h"
#include "GridCreator.h"

namespace Lebedev {
    class SphericalSurfaceIntegrator{
    public:
        explicit SphericalSurfaceIntegrator(const OrderType& orderType = OrderType::LD0006)
                : gridCreator_(orderType){};

        double integrate(SpatialFunction &f) const {
            const auto& xyzw = gridCreator_.grid();
            double integral = 0.0;

            for (int i = 0; i < xyzw.rows(); ++i) {
                integral += f.value(xyzw.row(i).head(3)) * xyzw.row(i)[3];
            }
            return 4*M_PI*integral;
        };


    void changeGrid(const OrderType& orderType){
        gridCreator_.changeGrid(orderType);
    };

    private:
        GridCreator gridCreator_;
    };
};

#endif //SPHERICALSURFACEINTEGRATOR_H
