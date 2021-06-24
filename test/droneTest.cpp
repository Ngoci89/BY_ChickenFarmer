#include <gtest/gtest.h>
#include <drones/drone.h>

TEST(Drone, NoDrones) {
    auto input = R"(5 5
)";
    EXPECT_EQ(processCommands(input), "");
}

TEST(Drone, NoCommands) {
    auto input = R"(5 5
1 3 N
)";
    EXPECT_EQ(processCommands(input), "1 3 N\n");
}

 TEST(Drone, TurnLeftFromNorth) {
     auto input = R"(5 5
1 2 N
L
)";
    EXPECT_EQ(processCommands(input), "1 2 W\n");
 }

 TEST(Drone, TurnRightFromNorth) {   
     auto input = R"(5 5
1 2 N
R
)";
     EXPECT_EQ(processCommands(input), "1 2 E\n");
 }

 TEST(Drone, TurnLeftFromSouth) {    
     auto input = R"(5 5
1 2 S
L
)";
     EXPECT_EQ(processCommands(input), "1 2 E\n");
 }

 TEST(Drone, TurnRightFromSouth) {    
     auto input = R"(5 5
1 2 S
R
)";
     EXPECT_EQ(processCommands(input), "1 2 W\n");
 }

 TEST(Drone, TurnLeftFromWest) {    
     auto input = R"(5 5
1 2 W
L
)";
     EXPECT_EQ(processCommands(input), "1 2 S\n");
 }

 TEST(Drone, TurnRightFromWest) {
     auto input = R"(5 5
1 2 W
R
)";
     EXPECT_EQ(processCommands(input), "1 2 N\n");
 }

 TEST(Drone, TurnLeftFromEast) {    
     auto input = R"(5 5
1 2 E
L
)";
     EXPECT_EQ(processCommands(input), "1 2 N\n");
 }

 TEST(Drone, TurnRightFromEast) {    
     auto input = R"(5 5
1 2 E
R
)";
     EXPECT_EQ(processCommands(input), "1 2 S\n");
 }

 TEST(Drone, MoveFromZeroHeadingNorth) {
     auto input = R"(5 5
1 2 N
M
)";
     EXPECT_EQ(processCommands(input), "1 3 N\n");
 }

 TEST(Drone, MoveFromZeroHeadingSouth) {
     auto input = R"(5 5
1 2 S
M
)";
     EXPECT_EQ(processCommands(input), "1 1 S\n");
 }

 TEST(Drone, MoveFromZeroHeadingWest) {
     auto input = R"(5 5
1 2 W
M
)";
     EXPECT_EQ(processCommands(input), "0 2 W\n");
 }

 TEST(Drone, MoveFromZeroHeadingEast) {
     auto input = R"(5 5
1 2 E
M
)";
     EXPECT_EQ(processCommands(input), "2 2 E\n");
 }

 TEST(Drone, CommandSequence) {
    auto input = R"(5 5
1 2 N
MRMLM
)";

    EXPECT_EQ(processCommands(input), "2 4 N\n");
}
 //main acceptance criteria of the task
TEST(Drone, AcceptanceTest) {
    auto input = R"(5 5
1 2 N
LMLMLMLMM
3 3 E
MMRMMRMRRM
)";

    EXPECT_EQ(processCommands(input), "1 3 N\n5 1 E\n");  
}

TEST(Drone, InvalidPosition) {
    auto input = R"(5 5
1
M
)";
    EXPECT_THROW(processCommands(input), std::runtime_error);
}
TEST(Drone, CrashNorth) {
    auto input = R"(5 5
1 5 N
M
)";
    EXPECT_THROW(processCommands(input), std::runtime_error);
}

TEST(Drone, CrashEast) {
    auto input = R"(5 5
5 1 E
M
)";
    EXPECT_THROW(processCommands(input), std::runtime_error);
}

TEST(Drone, CrashSouth) {
    auto input = R"(5 5
1 0 S
M
)";
    EXPECT_THROW(processCommands(input), std::runtime_error);
}

TEST(Drone, CrashWest) {
    auto input = R"(5 5
0 5 W
M
)";
    EXPECT_THROW(processCommands(input), std::runtime_error);
}

TEST(Drone, InvalidDirection) {
    auto input = R"(5 5
0 5 T
M
)";
    EXPECT_THROW(processCommands(input), std::runtime_error);
}

TEST(Drone, InvalidCommand) {
    auto input = R"(5 5
0 5 W
Z
)";
    EXPECT_THROW(processCommands(input), std::runtime_error);
}