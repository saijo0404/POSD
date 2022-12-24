#pragma once

#include <stack>
#include "command.h"
#include "macro_command.h"

class CommandHistory {
private:
    bool inMacro = false;
    std::stack<Command *> _history;
    std::stack<Command *> _undoCommands;

public:
    CommandHistory() {}
    ~CommandHistory() {
        while ( !_history.empty() ) {
            delete _history.top();
            _history.pop();
        }
        while ( !_undoCommands.empty() ) {
            delete _undoCommands.top();
            _undoCommands.pop();
        }
    }

    void beginMacroCommand() { 
        Command *macro_command = new MacroCommand();
        _history.push(macro_command);
        inMacro = true; 
    }

    void addCommand(Command *command) { 
        if ( inMacro ) { _history.top()->addCommand(command); }
        else { _history.push(command); }
    }

    void endMacroCommand() { inMacro = false; }

    void undo() {
        if ( _history.size()!=0 ) {
            _history.top()->undo();
            _undoCommands.push(_history.top());
            _history.pop();
        }
        else { std::cout << "can't undo." << std::endl; }
    }

    std::stack<Command *> getHistory() { return _history; }
};