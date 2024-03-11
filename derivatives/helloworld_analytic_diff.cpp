#include <ceres/ceres.h>
#include "glog/logging.h"
#include <vector>

class QuadraticCostFunction : public ceres::SizedCostFunction<1/*number of residuals*/,1/*size of first parameter*/>
{
public:
    bool Evaluate(double const* const* parameters,
                    double* residuals,
                    double** jacobians) const override{
                        double x =parameters[0][0];
                        residuals[0]=10-x;
                        if(jacobians!=nullptr && jacobians[0]!=nullptr){
                            jacobians[0][0]=-1;
                        }
                        return true;
                    }

};

int main(int argc, char const *argv[])
{
    google::InitGoogleLogging(argv[0]);

    double x=0.5;
    const double initial_x=x;

    ceres::CostFunction* cost_function = new QuadraticCostFunction;
    ceres::Problem problem;
    problem.AddResidualBlock(cost_function,nullptr,&x);

    //run the solver
    ceres::Solver::Options options;
    options.minimizer_progress_to_stdout=true;
    ceres::Solver::Summary summary;
    ceres::Solve(options,&problem,&summary);

    std::cout<<summary.BriefReport()<<std::endl;


    return 0;
}



