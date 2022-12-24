#include "../mock_drag_and_drop.h"
#include "../../../../src/graphics/drag_and_drop/command/move_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"

TEST(MoveCommandTest, MoveCommand) {
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(0, 0);
    MoveCommand moveCommand(&mockDragAndDrop, &history);
    moveCommand.execute();
    ASSERT_NEAR(0, mockDragAndDrop.getMoveX(), 0.001);
    ASSERT_NEAR(0, mockDragAndDrop.getMoveY(), 0.001);

    MoveCommand moveCommand1(moveCommand);
    moveCommand1.execute();
    ASSERT_NEAR(0, mockDragAndDrop.getMoveX(), 0.001);
    ASSERT_NEAR(0, mockDragAndDrop.getMoveY(), 0.001);

    MousePosition::getInstance()->setPos(1, 1);
    MoveCommand *copied = (MoveCommand *)history.getHistory().top();
    copied->undo();
    // moveCommand1.undo();
    ASSERT_NEAR(0, mockDragAndDrop.getMoveX(), 0.001);
    ASSERT_NEAR(0, mockDragAndDrop.getMoveY(), 0.001);

    MockCommand mockCommand;
    ASSERT_ANY_THROW(moveCommand1.addCommand(&mockCommand));
    ASSERT_ANY_THROW(moveCommand1.getCommands());

}
