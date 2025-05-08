# GitHub Copilot C++ Quick Commands & Features Cheatsheet

**1. GitHub Copilot Chat (Main Panel)**

* **Access:** Open via VS Code Activity Bar or Command Palette.
* **Key Participants (`@` prefix - Rule: Max ONE per prompt):**
    * `@workspace`: Context of your entire open project/folder. For project-aware tasks.
    * `@vscode`: Context of your VS Code editor settings & state. For editor-related questions.
    * `@terminal`: Context from the integrated terminal (focuses on recent commands/output & selection).
* **Key Context Variables (`#` prefix):**
    * `#file:PATH/TO/FILE.cpp` (or type `#file` & select from UI list): Specific file(s).
        * *Tip: Drag files/folders from VS Code Explorer into Chat input.*
    * `#selection`: Code currently selected in your active editor.
    * `#symbol:MyClass::myMethod` (or type `#symbol` & select): A specific C++ symbol.
    * `#fetch:URL`: Fetches content from a public URL to use as context.
    * `#terminalLastCommand`: The last command run in the VS Code integrated terminal.
    * `#terminalSelection`: Text currently selected in the integrated terminal.
    * **Tip for using `#` variables:** Type `#` then begin typing the name (file, symbol, etc.). VS Code's UI will suggest matches from your workspace, often eliminating the need for full paths. Effective context improves suggestion quality.
    * **Note on `@workspace` vs. `#codebase`:**
        * `@workspace` is the standard **participant** for general project queries.
        * `#codebase` (a **variable**) also provides workspace context. It can be more versatile, sometimes used in Edits/Agent modes or if workspace context is needed alongside a different participant (though such combinations are rare).
* **Common Slash Commands:**
    * `/explain` (e.g., `#selection /explain`): Explains code or concepts.
    * `/fix` (e.g., `@workspace #selection /fix this logic error`): Proposes fixes for code or errors.
    * `/tests` (e.g., `@workspace #file:src/utils.cpp /tests`): Generates unit tests.
    * `/doc` (e.g., `#selection /doc`): Generates documentation comments (e.g., Doxygen) for selected code. Works in main Chat and Inline Chat.
    * `/clear`: Clears the current chat session history.
* **Combining Context & Commands (Examples):**
    * `@workspace /explain #file:src/main.cpp What is the main purpose of this file?`
    * `@workspace #selection /tests Generate a test case for this function.`
    * `@vscode How do I configure the C++ IntelliSense mode for this project?`
* **Interacting with Chat Responses:**
    * Insert code into active editor, copy, run commands in terminal.
    * Use "Edits Mode" (pencil icon on suggestion or `Cmd+E`/`Ctrl+E`) for direct application of changes to selected code or to populate manually created empty files.

**2. Inline Chat (In-Editor)**

* **Access:** `Cmd+I` (macOS) or `Ctrl+I` (Windows/Linux) with code selected or cursor in place.
* **Usage:** Quick explanations, refactoring, documentation, or small code generations directly within the editor, using surrounding/selected code as context.
* **Slash Commands:** `/explain`, `/fix`, `/doc` are highly effective here.
* **Review Suggestions:** Cycle through multiple suggestions if offered (e.g., `Alt+]` or `Option+]`, or check Command Palette for "GitHub Copilot: View Next/Previous Suggestion").

**3. Code Completions (As You Type)**

* **Automatic Suggestions:** Receive real-time C++ code suggestions while typing.
* **Trigger:** Suggestions typically appear automatically as you type or after a brief pause. Standard editor auto-completion triggers (e.g., often `Ctrl+Space`, though this can vary by editor setup) may also show Copilot suggestions alongside other editor-provided completions.
* **Interaction:** `Tab` to accept a full suggestion, `Esc` to dismiss. Review and accept parts of multi-line suggestions.

**4. Guiding & Customizing Copilot**

* **Workspace Instructions (`.github/copilot-instructions.md`):**
    * **What:** Project-wide, persistent, high-level guidance (e.g., C++17, CMake, architecture, general coding style).
* **Custom Instructions (via `.vscode/settings.json` linking `.md` files):**
    * **What:** Detailed, specific rules for tasks like code generation (`docs/instructions/codegen_cpp.md`) or test generation (`docs/instructions/testgen_cpp.md`).
    * **How:** Reference your `.md` instruction files in VS Code's workspace `settings.json` (e.g., using keys like `github.copilot.chat.codeGeneration.instructions` – *always check current Copilot documentation for exact setting keys*).
* **Feature Specifications (User-created `.md` in `docs/features/`):**
    * **What:** Your detailed written requirements for a feature *before* coding.
    * **How:** Reference this spec file in prompts (e.g., `@workspace #file:docs/features/my_feature.md Implement this...`).
* **"Agent" Workflows (User-created `.md` in `docs/workflows/`):**
    * **What:** Your custom multi-step instructions for Copilot to follow for complex tasks.
    * **How:** Reference workflow file in Chat, providing specific inputs like the feature spec path.
* **Reusable Prompts (`.prompts/*.prompt.md` files):**
    * **What:** Your library of parameterized prompts for common, smaller C++ tasks.
    * **How:** Invoke via `# (select .prompts/my_prompt.md)` in Chat.

**Important Reminders:**

* **File Creation:** Manually create new folders and empty `.h`/`.cpp` files. Then, use Copilot Chat (Edits Mode is effective) to populate these files.
* **Review All Suggestions:** Always critically review, test, and understand code generated by Copilot.

---