#include "glog/logging.h"
#include <ceres/ceres.h>
struct CostFunctor 
{
    bool operator()(const double* const x,double* residual) const {
        residual[0]=10.0-x[0];
        return true;
    }
};

int main(int argc, char const *argv[])
{
    google::InitGoogleLogging(argv[0]);
    ceres::CostFunction* cost_function =new ceres::NumericDiffCostFunction<CostFunctor, ceres::CENTRAL, 1, 1>(new CostFunctor);
    
    double x=0.5;
    const double initial_x=x;

    //build problem
    ceres::Problem problem;
    problem.AddResidualBlock(cost_function,nullptr,&x);

    //run the solver
    ceres::Solver::Options options;
    options.minimizer_progress_to_stdout=true;
    ceres::Solver::Summary summary;
    ceres::Solve(options,&problem,&summary);

    std::cout<<summary.BriefReport()<<std::endl;
    std::cout<<"x:"<<initial_x<<"->"<<x<<"\n";
    return 0;

}

