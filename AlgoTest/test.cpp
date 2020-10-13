#include "pch.h"
#include <vector>

#include "..\GraphingAlgos\Algos.h"

TEST(Cyclic_, Directet) {
  
  std::vector<std::vector<int>> edges = {
	  {1,2},
	  {2,3},
	  {3,1}
  };

  EXPECT_TRUE(isCyclicDirect(edges));

}

