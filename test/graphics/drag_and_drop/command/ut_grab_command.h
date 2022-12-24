#include "../mock_drag_and_drop.h"
#include "../../../../src/graphics/drag_and_drop/command/grab_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"

TEST(GrabCommandTest, GrabCommand) {
    MockDragAndDrop mockDragAndDrop;
    CommandHistory history;
    MousePosition::getInstance()->setPos(0, 0);
    GrabCommand grabCommand(&mockDragAndDrop, &history);
    grabCommand.execute();
    ASSERT_NEAR(0, mockDragAndDrop.getDragX(), 0.001);
    ASSERT_NEAR(0, mockDragAndDrop.getDragY(), 0.001);

    GrabCommand grabCommand1(grabCommand);
    grabCommand1.execute();
    ASSERT_NEAR(0, mockDragAndDrop.getDragX(), 0.001);
    ASSERT_NEAR(0, mockDragAndDrop.getDragY(), 0.001);

    MousePosition::getInstance()->setPos(1, 1);
    GrabCommand *copied = (GrabCommand *)history.getHistory().top()->getCommands()[0];
    copied->undo();
    ASSERT_NEAR(0, mockDragAndDrop.getDragX(), 0.001);
    ASSERT_NEAR(0, mockDragAndDrop.getDragY(), 0.001);

    MockCommand mockCommand;
    ASSERT_ANY_THROW(grabCommand1.addCommand(&mockCommand));
    ASSERT_ANY_THROW(grabCommand1.getCommands());
}