#include "mock_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"

#include <stack>


TEST(CommandHistoryTest, CommandHistory) {
    CommandHistory history;
    history.beginMacroCommand();
    std::stack<Command *> _hist = history.getHistory();
    ASSERT_EQ(1, _hist.size());
    ASSERT_TRUE(dynamic_cast<MacroCommand *>(_hist.top()) != nullptr);

    MockCommand* mockCommand = new MockCommand();
    history.addCommand(mockCommand);
    history.endMacroCommand();
    _hist = history.getHistory();
    ASSERT_EQ(1, _hist.size());
    ASSERT_EQ(1, _hist.top()->getCommands().size());
    ASSERT_EQ(mockCommand, _hist.top()->getCommands()[0]);
    
    MockCommand* mockCommand1 = new MockCommand();
    history.addCommand(mockCommand1);
    _hist = history.getHistory();
    ASSERT_EQ(2, _hist.size());
    ASSERT_EQ(mockCommand1, _hist.top());

    history.undo();
    _hist = history.getHistory();
    ASSERT_EQ(1, _hist.size());
    ASSERT_TRUE(dynamic_cast<MacroCommand *>(_hist.top()) != nullptr);
}