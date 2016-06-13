#include <gtest/gtest.h>

#include <QSqlDatabase>

#include <Database.h>

class DatabaseTest : public testing::Test
{
    protected:
        DatabaseTest(void)
        {
        }
        
        virtual ~DatabaseTest(void)
        {
        }
        
        virtual void SetUp(void)
        {
            db = new Database();
        }
        
        virtual void TearDown(void)
        {
            delete db;
        }
        
        Database *db;
};

TEST_F(DatabaseTest, ConnectionTest)
{
    EXPECT_EQ(true, db->open());
}