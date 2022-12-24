#include "mock_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command.h"
#include "../../../../src/graphics/drag_and_drop/command/macro_command.h"

#include <vector>

TEST(MacroCommandTest, MacroCommand) {
    MacroCommand macroCommand;
    MockCommand* mockCommand = new MockCommand();
    MockCommand * mockCommand1 = new MockCommand();
    macroCommand.addCommand(mockCommand);
    std::vector<Command *> commands = macroCommand.getCommands();
    ASSERT_EQ(1, commands.size());
    ASSERT_EQ(mockCommand, commands[0]);
    macroCommand.addCommand(mockCommand1);
    macroCommand.execute();
    ASSERT_TRUE(mockCommand->isExecuteCalled());
    macroCommand.undo();
    ASSERT_TRUE(mockCommand->isUndoCalled());
}