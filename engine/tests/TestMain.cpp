#include "gtest/gtest.h"

#include <Engine.h>

const char executable[] = "engine";

class TestMain : public ::testing::Test
{
protected:
    // Adjust number of args as needed for the program if necessary.  Note that    
#ifdef _WIN32
    int testMain(const char* arg1, const char* arg2 = nullptr, const char* arg3 = nullptr) {
        int commandSize = sizeof(executable);
        int arg1size = 0;
        int arg2size = 0;
        int arg3size = 0;        

        if (arg1) {
            arg1size = sizeof(arg1);
        }
        if (arg2) {
            arg2size += sizeof(arg2);
        }
        if (arg3) {
            arg3size += sizeof(arg3);
        }
        int totalSize = commandSize + 4 + arg1size + arg2size + arg3size + 4;
        std::unique_ptr<char[]> command(new char[totalSize]);
        memset(command.get(), 0, totalSize);

        strncat(command.get(), executable, commandSize);
        strncat(command.get(), ".exe", 4);
        if (arg1size > 0) {
            strncat(command.get(), " ", 1);
            strncat(command.get(), arg1, arg1size);
        }
        if (arg2size > 0) {
            strncat(command.get(), " ", 1);
            strncat(command.get(), arg2, arg2size);
        }
        if (arg3size > 0) {
            strncat(command.get(), " ", 1);
            strncat(command.get(), arg3, arg3size);
        }
        int retVal = system(command.get());        
        
        return retVal;
    }
#else
    int testMain(const char *arg1, const char *arg2=nullptr, const char *arg3=nullptr)
    {
        pid_t p = -1;
        int stat;
        int arg_count = 0;

        p = fork();

        EXPECT_FALSE(p < 0);
        if (p == 0)
        {
            execl(executable, executable, arg1, arg2, arg3, NULL);
        }
        else
        {
            wait(&stat);
            if (WIFEXITED(stat)){
                arg_count = WEXITSTATUS(stat);
            }
        }
        return arg_count;
    }    
#endif
};

TEST_F(TestMain, RunMain)
{    
    EXPECT_EQ(testMain("1","2"), 3) << " result did not equal 3";
    EXPECT_EQ(testMain("1"), 2) << " result did not equal 2";
    EXPECT_EQ(testMain("1","2","3"), 4) << " result did not equal 4"; 
}

