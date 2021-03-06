#ifndef UPO_RRT_SIMPLE_RRT_STAR_
#define UPO_RRT_SIMPLE_RRT_STAR_

#include <upo_rrt_planners/StateSpace.h>
#include <upo_rrt_planners/State.h>
#include <upo_rrt_planners/Node.h>
#include <upo_rrt_planners/StateChecker.h>
#include <upo_rrt_planners/NearestNeighborsFLANN.h>
#include <upo_rrt_planners/NearestNeighbors.h>
#include <upo_rrt_planners/planners/Planner.h>

#include <vector>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <sys/time.h>

namespace upo_RRT
{
	class SimpleRRTstar : public upo_RRT::Planner
	{
		public:

			SimpleRRTstar();
			~SimpleRRTstar();

			State* steer(State* fromState, State* toState, std::vector<State>& istates);

			std::vector<upo_RRT::Node> solve(float secs);


			void setMaxRange(float range) {
				maxRange_ = range;
				steering_->setMaxRange(range);
			}

			
			void set_useKnearest(bool b) {
				useKnearest_ = b;
			}
			
			void setRewireFactor(float f) {
				rewire_factor_ = f;
			}
			
			void set_useFirstPathBiasing(bool b) {
				useFirstPathBiasing_ = b;
			}
			
			
			
			void getNearestNeighbors(Node* node, std::vector<Node*> &nbrs);
			
			void calculateParamsNearest();
			
			//float motionCost(Node* n1, Node* n2); 
			
			bool collisionFree(State* fromState, State* toState, std::vector<State>& istates);
			
			
		

		private:

			//float 				timeStep_; //should be 1/freq  with freq = freq of the controller(15~20Hz)
			//float 				minControlSteps_; //minTime = timeStep*minControlDuration
			//flaot 				maxControlSteps_;

			float 				maxRange_; //max distance to insert a new node

			bool 				useKnearest_;
			double				k_rrt_;
			double 				r_rrt_;
			float  				rewire_factor_;
			
			bool 				useFirstPathBiasing_;
			
			
			
	};
}
#endif
