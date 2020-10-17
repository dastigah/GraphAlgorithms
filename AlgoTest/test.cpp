#include "pch.h"
#include <vector>

#include "..\GraphingAlgos\Algos.h"

TEST(Cyclic_Test, DirectedCyclicNormal) {

	std::vector<std::vector<int>> edges = {
		{1,2},
		{2,3},
		{3,1}
	};

	EXPECT_TRUE(isCyclicDirect(edges));

	edges = {
		{1,2},
		{1,3},
		{2,4},
		{3,4},
		{4,1}
	};

	EXPECT_TRUE(isCyclicDirect(edges));

}

