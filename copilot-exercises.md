# GitHub Copilot Exercises: Specification-Driven Development & Customization (C++ Car Simulation)

**Session Goal:** Learn to effectively guide and customize GitHub Copilot for extending a C++ project. This session focuses on planning with AI, defining detailed specifications and guidelines (code style, quality, testing, architectural consistency), creating reusable prompts, defining and refining agent workflows, and iteratively developing features based on these structured inputs.

**Project Context:** We start with the existing "Car Simulation" C++ project. It includes a basic `Vehicle` class, a `Road` class, a `main.cpp` to run a simple simulation, and a `CMakeLists.txt` for building. The goal is to extend this simulation with new features.

**Key Customization Mechanisms & Copilot Features:**

* **Workspace Contextual Understanding:** Copilot's ability to use open files and workspace content (`@workspace` in chat).
* **Workspace Instructions (`.github/copilot-instructions.md`):** Persistent, high-level context about the project, technologies, and overall goals.
* **Custom Instructions (VS Code Settings / Referenced Files):** Specific guidelines for Copilot's behavior during code generation, test generation, explanations, etc. Often configured via `settings.json` by referencing external `.md` instruction files (e.g., from a `docs/instructions/` folder).
* **Reusable Prompts (`*.prompt.md`):** Parameterized instructions for common, well-defined, limited-scope tasks, invokable in chat. (Note: A specific exercise for creating one has been removed for brevity, but the mechanism remains relevant).
* **Agent Workflow Instructions (Separate `.md` File):** Detailed, multi-step instructions to guide Copilot (especially in agent-like interactions or complex chat sequences) through more complex tasks like implementing a feature based on a specification.
* **Copilot Chat Features:**
    * `@workspace` for broad context.
    * `#file:` references for specific file context.
    * `/explain`, `/fix`, `/tests`, `/doc` commands.
    * Edits Mode (pencil icon or `Cmd+E`/`Ctrl+E`) for focused code modifications, including populating empty files.
    * Inline Chat (`Cmd+I`/`Ctrl+I`) for quick, in-editor interactions.

**Prerequisites:**

* Familiarity with basic Copilot Chat features from any previous introductory sessions.
* A C++17 compatible compiler (e.g., GCC, Clang, MSVC).
* CMake (version 3.10 or higher).
* Git and a Git client.
* VS Code with the latest GitHub Copilot and GitHub Copilot Chat extensions enabled.
* A basic understanding of C++ and CMake.
* Knowledge of how to access and modify VS Code workspace settings (`.vscode/settings.json`).
* **Note on File Creation:** Throughout these exercises, when new documentation or instruction files are needed, you will be asked to first manually create any necessary folders and then create an empty file with the specified name and path. After creating and opening the empty file, you will use Copilot Chat or Edits mode to populate it with the described content.

---

## Section 1: Understanding the Existing C++ Project & Setting Up Copilot Context

**Goal:** Familiarize yourself with the existing C++ Car Simulation codebase using Copilot Chat and establish initial high-level instructions for Copilot.

---

### Exercise 1.1: Explore Existing Codebase with Copilot Chat

* **Purpose:** To understand the structure and functionality of the initial C++ project.
* **Aim:** Use Copilot Chat to analyze and explain the key components of the car simulation.
* **Steps:**
    1.  Clone the `copilot-cpp-exercise` repository (if you haven't already) and open it in VS Code.
    2.  Open `Vehicle.h` and `Vehicle.cpp`. In Copilot Chat, ask:
        * `@workspace #file:src/Vehicle.h #file:src/Vehicle.cpp /explain What are the main responsibilities and functionalities of the Vehicle class?`
    3.  Open `Road.h` and `Road.cpp`. In Copilot Chat, ask:
        * `@workspace #file:src/Road.h #file:src/Road.cpp /explain How does the Road class manage vehicles and represent the road?`
    4.  Open `main.cpp`. In Copilot Chat, ask:
        * `@workspace #file:src/main.cpp /explain What is the basic simulation loop implemented in main.cpp?`
    5.  Open `CMakeLists.txt`. In Copilot Chat, ask:
        * `@workspace #file:CMakeLists.txt /explain What are the key parts of this CMakeLists.txt file? How is the C++ standard set? How is the executable built?`

### Exercise 1.2: Initialize Workspace Instructions (`.github/copilot-instructions.md`)

* **Purpose:** To provide Copilot with persistent, high-level context about the C++ Car Simulation project.
* **Aim:** Create and populate the `.github/copilot-instructions.md` file with essential project information.
* **Steps:**
    1.  At the root of your project, create a folder named `.github` if it doesn't already exist.
    2.  Inside the `.github` folder, manually create an empty file named `copilot-instructions.md`.
    3.  Open the newly created empty `copilot-instructions.md` file in VS Code.
    4.  Use Copilot Chat to populate this active file. For example, you can open Copilot Chat (Ctrl+Cmd+I or similar shortcut) and type your prompt directly, or use Edits mode on the empty file:
        *Prompt for Chat (ensure `copilot-instructions.md` is the active editor tab):*
        `@workspace Populate this active file with initial Copilot instructions for this C++ car simulation project. Include sections for:
        - Project Overview: C++17 car simulation on a circular road, built with CMake.
        - Core Technologies: C++17, CMake.
        - Initial Architectural Ideas: Vehicle class for state/movement, Road class manages vehicles, simulation loop in main.
        - General Aim: Modular and extensible design.`
    5.  Review the content inserted by Copilot into `copilot-instructions.md` and save the file.
    6.  **(Verification):** In Copilot Chat, ask `@workspace What C++ standard is this project intended to use?` Copilot should ideally pick this up from your instructions.

### Exercise 1.3: Discuss CMake Build System Further

* **Purpose:** To understand how to modify the CMake build for future extensions.
* **Aim:** Use Copilot Chat to explore common CMake tasks relevant to the project.
* **Steps:**
    1.  Open `CMakeLists.txt`.
    2.  In Copilot Chat, discuss:
        * `@workspace #file:CMakeLists.txt If I were to add new source files, say 'Truck.cpp' and 'Truck.h' in the 'src' directory, how would I modify this CMakeLists.txt to include them in the build?`
        * `@workspace #file:CMakeLists.txt How would I typically add an external library dependency using CMake, for example, if I wanted to use a library like Google Test? (Explain FetchContent or find_package).`
    3.  Review Copilot's explanations. This is for understanding at this stage.

---

## Section 2: Planning and Specifying a New Feature

**Goal:** Select a development direction from the project's `README.md`, then use Copilot to brainstorm, define, and document the feature specification *before* writing implementation code. We'll choose "Adding Different Vehicle Types" and specify a "Truck" type.

---

### Exercise 2.1: Brainstorm "Truck" Vehicle Type Details

* **Purpose:** To outline the characteristics and behavior of a new "Truck" vehicle type.
* **Aim:** Use Copilot Chat to discuss attributes and unique behaviors for a Truck.
* **Steps:**
    1.  Review the "Explore with GitHub Copilot: Development Directions" section in the project `README.md`, specifically the "Diverse Vehicle Behaviors and Types" idea.
    2.  Open Copilot Chat. Prompt:
        `@workspace We want to add a new vehicle type 'Truck' to the simulation. It should inherit from the existing Vehicle class. What specific attributes could a Truck have (e.g., slower acceleration, lower max speed, longer length)? How might its updateSpeed or updatePosition logic differ slightly from a standard Vehicle? Consider its interaction with other vehicles on the Road.`
    3.  Discuss Copilot's suggestions. Ask follow-up questions to refine the concept.

### Exercise 2.2: Create Feature Specification Document for "Truck"

* **Purpose:** To create a detailed written specification for the new "Truck" vehicle type.
* **Aim:** Manually create the file `docs/features/01_truck_vehicle_type.md`, then use Copilot Chat or Edits mode to populate it.
* **Steps:**
    1.  At the project root, create a folder named `docs` if it doesn't exist. Inside `docs`, create a folder named `features` if it doesn't exist.
    2.  Inside `docs/features/`, manually create an empty file named `01_truck_vehicle_type.md`.
    3.  Open the empty `01_truck_vehicle_type.md` file in VS Code.
    4.  Use Copilot Chat (with the file active or referenced) or Edits mode to generate the content.
        *Prompt for Chat (ensure `01_truck_vehicle_type.md` is the active editor tab):*
        `@workspace Populate this active file with a detailed feature specification in Markdown format for adding a 'Truck' vehicle type to our C++ Car Simulation. The Truck should inherit from the 'Vehicle' class. Based on our earlier discussion (slower acceleration, lower max speed, potentially longer length affecting spacing), cover these sections:
        1.  **Feature Title:** Add Truck Vehicle Type
        2.  **Version:** 1.0
        3.  **Goal:** Introduce a Truck class as a new type of vehicle with distinct movement characteristics.
        4.  **Requirements:**
            * Truck class inherits from Vehicle.
            * Truck has attributes: default max speed (e.g., 2), default acceleration rate (e.g., 1, if Vehicle class is refactored to use acceleration rate), length (e.g., 2 cells).
            * Truck's constructor initializes these attributes.
            * Truck's `updateSpeed` method might be overridden or influenced by its specific max speed/acceleration.
            * Truck's presence on the road should be visually distinct if console output is enhanced later (e.g., 'T' instead of 'V'). For now, focus on data model.
            * The `Road` class should be able to manage `Vehicle` pointers that could point to `Truck` objects.
        5.  **Impacted Files (Expected):**
            * `src/Truck.h` (new)
            * `src/Truck.cpp` (new)
            * `src/Vehicle.h` (potential changes if base class needs adjustments for extensibility, e.g. virtual destructor, protected members, or common acceleration logic).
            * `src/Road.h` & `src/Road.cpp` (minor changes for adding trucks, if any).
            * `src/main.cpp` (to instantiate and add trucks to the simulation).
            * `CMakeLists.txt` (to add new source files).
        6.  **Open Questions/Considerations:**
            * How will 'length' attribute affect the 'distanceToNext' calculation or clear space check? (For now, can defer complex logic, but note it).`
    5.  Review and refine the content inserted by Copilot into `01_truck_vehicle_type.md`. Save the file.

### Exercise 2.3: Validate Feature Specification with a Powerful LLM

* **Purpose:** To critically assess the generated feature specification using an advanced AI model for a second opinion.
* **Aim:** Submit the feature specification to a powerful LLM (e.g., via its web interface or API if available) for assessment, explicitly instructing it *not* to generate code.
* **Steps:**
    1.  Copy the complete content of your `docs/features/01_truck_vehicle_type.md` specification.
    2.  Access a powerful Large Language Model you have access to (e.g., Claude 3 Opus, GPT-4, Gemini 1.5 Pro).
    3.  Paste the specification into the LLM's input interface with a prompt like the following:
        `"Please assess the following C++ feature specification for a car simulation project. Focus on its clarity, completeness for a developer to implement, potential ambiguities, missing considerations, or contradictions with typical C++ object-oriented design or simulation logic. The existing project has 'Vehicle' and 'Road' classes.
        IMPORTANT: ONLY provide assessment and feedback on the specification itself. DO NOT generate any C++ code, suggest specific code snippets, or attempt to implement any part of this feature. Your role is strictly to review the written specification.

        [Paste your specification content here]" `
    4.  Review the feedback from the LLM. Consider its points and update your `01_truck_vehicle_type.md` specification in VS Code if you find the suggestions valuable.

### Exercise 2.4: Update/Generate Architectural Diagram

* **Purpose:** To visualize how the new "Truck" class fits into the existing architecture.
* **Aim:** Use Copilot Chat to generate/update a Mermaid class diagram in `docs/architecture/SystemDiagram.md`.
* **Steps:**
    1.  Inside the `docs` folder, create a folder named `architecture` if it doesn't exist.
    2.  Manually create an empty file named `SystemDiagram.md` in the `docs/architecture/` folder. Open it.
    3.  Open Copilot Chat. Prompt:
        `@workspace Based on the existing classes (Vehicle, Road, Main) and the feature specification for adding a 'Truck' class that inherits from 'Vehicle' (#file:docs/features/01_truck_vehicle_type.md), generate a Mermaid class diagram description. Show inheritance and key relationships. I will paste this into docs/architecture/SystemDiagram.md.`
    4.  Copy the generated ```mermaid ... ``` block from Copilot's response.
    5.  Paste the Mermaid block into your open `SystemDiagram.md` file and save it. If you have a Mermaid preview extension in VS Code, check the diagram.

---

## Section 3: Defining Copilot Customization & Guidelines for C++

**Goal:** Configure Copilot's behavior for C++ code generation and testing by creating custom instruction files, primarily driven by Copilot's suggestions, and referencing them in VS Code settings.

---

### Exercise 3.1: Define Custom C++ Code Generation Instructions

* **Purpose:** To guide Copilot towards generating C++ code that meets specific project standards, with an initial draft proposed by Copilot.
* **Aim:** Create and populate `docs/instructions/copilot_codegen_cpp_instructions.md` by prompting Copilot for suggestions, then refine and reference it in settings.
* **Steps:**
    1.  Inside the `docs` folder, create a folder named `instructions` if it doesn't exist.
    2.  Inside `docs/instructions/`, manually create an empty file named `copilot_codegen_cpp_instructions.md`.
    3.  Open the empty `copilot_codegen_cpp_instructions.md` file in VS Code.
    4.  Use Copilot Chat (with the file active) or Edits mode to get an initial draft of guidelines.
        *Prompt for Chat (ensure `copilot_codegen_cpp_instructions.md` is the active editor tab):*
        `@workspace This project is a C++17 car simulation built with CMake. Populate this active file with a suggested set of C++ code generation guidelines. I'm looking for best practices covering areas like:
        - C++ Standard adherence.
        - Header file conventions (guards, includes, forward declarations).
        - Class design principles (constructors, destructors, const correctness, member initialization).
        - Memory management (e.g., use of smart pointers like std::shared_ptr which is already in use).
        - Commenting style (e.g., Doxygen).
        - Basic error handling approaches suitable for this project.
        - Naming conventions for classes, functions, and variables.
        Please propose a structured set of guidelines in Markdown.`
    5.  Review Copilot's proposed guidelines. Discuss with Copilot if needed: "Can you elaborate on header guard best practices?" or "What's a good, simple naming convention for private member variables in C++?". Refine the guidelines until you are satisfied. Save the file.
    6.  **Open Workspace Settings (JSON):** Command Palette (`Ctrl+Shift+P` or `Cmd+Shift+P`) -> `Preferences: Open Workspace Settings (JSON)`.
    7.  **Reference Instruction File:** Add the setting to reference your instruction file. The exact key might vary with Copilot versions (e.g., `github.copilot.chat.codeGeneration.instructions` or similar); consult current GitHub Copilot documentation. Example:
        ```json
        {
          // ... other settings ...
          "github.copilot.chat.codeGeneration.instructions": [
            {
              "file": "docs/instructions/copilot_codegen_cpp_instructions.md"
            }
          ]
        }
        ```
    8.  Save `settings.json`.

### Exercise 3.2: Plan for Testing & Define Test Generation Instructions

* **Purpose:** To set up a testing framework and define guidelines for generating tests, allowing for user choice in framework.
* **Aim:** Optionally add a testing framework (e.g., Google Test) to `CMakeLists.txt` and create/populate `docs/instructions/copilot_testgen_cpp_instructions.md` with general and framework-specific (if chosen) guidelines.
* **Steps - Part A: Add a Testing Framework to CMake (Optional - Example with Google Test)**
    1.  Decide if you want to integrate a specific C++ testing framework. Google Test is a common standard and will be used as an example. If you are familiar with another framework (e.g., Catch2, Boost.Test), you can adapt these steps or ask Copilot how to integrate it.
    2.  If proceeding with Google Test (or your chosen framework, adapting the prompt): Open `CMakeLists.txt`.
    3.  In Copilot Chat, ask for help:
        `@workspace #file:CMakeLists.txt Show me how to add Google Test to this project using CMake's FetchContent module. I want to be able to link my test executables against GTest.`
    4.  Review Copilot's suggestions (it should involve `WorkspaceContent_Declare`, `WorkspaceContent_MakeAvailable` for GTest, and guidance on linking). Carefully apply the changes to your `CMakeLists.txt`. For GTest, this might include:
        ```cmake
        # Near the top
        include(FetchContent)
        enable_testing() // Ensure testing is enabled

        # For GTest
        FetchContent_Declare(
          googletest
          GIT_REPOSITORY [https://github.com/google/googletest.git](https://github.com/google/googletest.git)
          GIT_TAG    release-1.14.0 // Or a more recent stable tag
        )
        FetchContent_MakeAvailable(googletest) // This makes GTest::gtest, GTest::gmock, GTest::gtest_main targets available
        ```
        Later, when you define a test executable, you'll use `target_link_libraries(your_test_executable PRIVATE GTest::gtest_main)` and `gtest_discover_tests(your_test_executable)`.
* **Steps - Part B: Create Test Generation Instructions**
    1.  Inside the `docs/instructions/` folder, manually create an empty file named `copilot_testgen_cpp_instructions.md`.
    2.  Open the empty `copilot_testgen_cpp_instructions.md` file in VS Code.
    3.  Use Copilot Chat (with the file active) or Edits mode to populate it.
        *Prompt for Chat (ensure `copilot_testgen_cpp_instructions.md` is active):*
        `@workspace Populate this active file with guidelines for generating C++ unit tests.
        Start with general principles:
        - Test public interfaces.
        - Aim for focused tests (one logical assertion or scenario per test).
        - Use descriptive names for test suites and individual tests.
        - Structure tests with clear Arrange, Act, Assert sections.
        - Consider edge cases, boundary conditions, and typical usage.
        Then, add a section for Google Test (if the user chose to set it up):
        - **Framework Specifics (Google Test Example):**
            - Include `gtest/gtest.h`.
            - Use `TEST(TestSuiteName, TestName) { ... }` for test cases.
            - Use GTest assertion macros (e.g., `ASSERT_EQ`, `EXPECT_TRUE`, `ASSERT_THROW`).
            - `TestSuiteName` often corresponds to the class being tested (e.g., `VehicleTest`).
            - Use test fixtures (`class MyFixture : public ::testing::Test`) for shared setup/teardown.
        If the user is using a different framework, they can adapt this section or ask for guidelines specific to their chosen framework.`
    4.  Review and save the file, tailoring it if you are using a framework other than Google Test.
    5.  **Open Workspace Settings (JSON)** and add/modify the setting for test generation instructions, referencing your new file. Example key (check Copilot docs for current official key, e.g., `github.copilot.tests.instructions` or a chat-specific one):
        ```json
        {
          // ... other settings ...
          "github.copilot.tests.instructions": [
            {
              "file": "docs/instructions/copilot_testgen_cpp_instructions.md"
            }
          ]
        }
        ```
    6.  Save `settings.json`.

---

## Section 4: Guided Feature Implementation & Generic Agent Workflow

**Goal:** Define a generic agent workflow for implementing features, and then apply it for the first time to implement the "Truck" feature.

---

### Exercise 4.1: Define Generic Agent Workflow for Feature Implementation

* **Purpose:** To create a reusable, structured set of instructions for Copilot to implement *any* new feature based on a provided specification.
* **Aim:** Create and populate `docs/workflows/implement_feature_workflow_v1.md` with generic steps.
* **Steps:**
    1.  Inside the `docs` folder, create a folder named `workflows` if it doesn't exist.
    2.  Inside `docs/workflows/`, manually create an empty file named `implement_feature_workflow_v1.md`.
    3.  Open the empty `implement_feature_workflow_v1.md` file in VS Code.
    4.  Populate this file using Copilot Chat (with the file active) or Edits mode, based on the example structure below.
        *Prompt fragment for Copilot:* `@workspace Populate this active file with a generic 'AI Agent Workflow: Implement Feature (v1)'.
        It should include:
        - A System Prompt defining the agent's role (C++ developer, use C++17, adhere to guidelines). Instruct it to **always** consult C++ code generation guidelines from `#file:docs/instructions/copilot_codegen_cpp_instructions.md`.
        - An "Input Variables from User Invocation" section (clarifying that `#featureSpecFile` is provided by user at invocation).
        - Generic Workflow Steps:
            1. Understand Requirements from the user-provided `#featureSpecFile`.
            2. File Scaffolding (User Task Reminder): Remind user to create empty .h/.cpp files for new classes as per spec. Agent will populate them.
            3. Implement Header File(s) for new/modified class(es) based on spec and guidelines.
            4. Implement Source File(s) for new/modified class(es) based on spec and guidelines.
            5. Modify Existing Files (e.g., base classes, manager classes, main.cpp, CMakeLists.txt) as indicated in spec or if logically necessary for integration, explaining any non-obvious changes.
            6. Build Check (Conceptual): State if code *should* compile.
            7. Report: List files to be created/modified, unimplemented parts, deviations.
        Ensure the workflow is general and does not mention 'Truck' or any specific feature names within its definition.`
        *Example content for the `implement_feature_workflow_v1.md` file:*
        ```markdown
        # AI Agent Workflow: Implement Feature (v1)

        ## System Prompt
        You are an expert C++ developer AI assistant. Your task is to implement a new feature for a C++17 car simulation project.
        You must strictly adhere to the provided feature specification (`#featureSpecFile` - which will be given by the user when they invoke this workflow).
        You **must always** consult and adhere to the project's C++ code generation guidelines, which are located at `#file:docs/instructions/copilot_codegen_cpp_instructions.md`.
        You will also follow existing architectural patterns of the codebase.

        ## Input Variables from User Invocation
        - `#featureSpecFile`: (Provided by user at invocation) Path to the Markdown file containing the detailed specification for the feature to be implemented.
        - `#workspace`: (Implicit) Access to the workspace code.

        ## Workflow Steps
        1.  **Understand Requirements:** Carefully read and analyze the feature specification provided in the user's `#featureSpecFile`. Identify all new classes, modifications to existing classes, and changes to the build system or main application logic.

        2.  **File Scaffolding (User Task Reminder):** The user is responsible for manually creating any necessary new empty `.h` and `.cpp` files in the `src/` directory (e.g., `src/[ClassNameFromSpec].h`, `src/[ClassNameFromSpec].cpp`) if the `#featureSpecFile` indicates new classes. You will populate these files.

        3.  **Implement Header File(s) (`.h`):** For each new class defined in the `#featureSpecFile`, generate the complete content for its header file. For existing classes that need modification, describe the changes to their header files.
            * Ensure all class definitions, member variable declarations, and method declarations align with the `#featureSpecFile` and the coding guidelines (`#file:docs/instructions/copilot_codegen_cpp_instructions.md`).
            * Include necessary header guards (e.g., `#pragma once`), forward declarations, and includes.
            * Apply Doxygen-style comments for classes and public members.

        4.  **Implement Source File(s) (`.cpp`):** For each new class, generate the complete content for its source file, implementing all methods declared in its header and specified in the `#featureSpecFile`. For existing classes, describe the changes or new method implementations in their source files.
            * Ensure all method implementations align with the `#featureSpecFile` and coding guidelines (`#file:docs/instructions/copilot_codegen_cpp_instructions.md`).
            * Initialize members correctly in constructors.

        5.  **Modify Supporting Files (as needed):**
            * **Base Classes/Related Classes:** If the `#featureSpecFile` requires changes to base classes (e.g., adding virtual methods, changing member visibility) or other interacting classes, detail these changes.
            * **`CMakeLists.txt`:** Specify the exact modifications needed to `CMakeLists.txt` to include any new `.cpp` files in the build.
            * **`main.cpp` (or other application entry points):** Detail how to modify `main.cpp` or other relevant files to integrate and demonstrate the new feature (e.g., instantiating new classes, calling new functions).

        6.  **Build Check (Conceptual):** Based on the generated and modified code, state whether the project *should* compile successfully. Note any potential compilation issues the user should watch out for.

        7.  **Report:**
            * List all new files for which content has been generated.
            * List all existing files that require modification, with a summary of changes for each.
            * Clearly note any parts of the `#featureSpecFile` that are not fully implemented in this pass or require further clarification.
            * Identify any necessary deviations from the `#featureSpecFile` and explain the reasoning.
        ```
    5.  Review the generic workflow. Ensure it doesn't contain specifics like "Truck." Save the file.

### Exercise 4.2: Execute Generic Agent Workflow for "Truck" Feature & Refine Code

* **Purpose:** To apply the newly defined generic agent workflow to implement the "Truck" feature specified earlier, and then iteratively refine the resulting code.
* **Aim:** Invoke the generic agent workflow, providing the "Truck" feature specification. Review the generated C++ code, build the project, and use Copilot's Edits/Inline Chat for improvements.
* **Steps:**
    1.  Ensure all referenced documents for the "Truck" feature and general guidelines exist:
        * `docs/features/01_truck_vehicle_type.md` (Your Truck spec)
        * `docs/instructions/copilot_codegen_cpp_instructions.md` (Your C++ codegen guidelines)
        * `docs/workflows/implement_feature_workflow_v1.md` (The generic workflow you just created)
    2.  **User Prerequisite from Workflow:** Based on your `01_truck_vehicle_type.md` spec, manually create empty `src/Truck.h` and `src/Truck.cpp` files.
    3.  In Copilot Chat, invoke the generic workflow, telling it which feature spec to use for this run.
        *Conceptual prompt for invoking the agent:*
        `@workspace Act as my AI C++ Developer assistant.
        Your task is to implement a new feature according to the detailed plan I provide.
        You must follow all instructions precisely from the generic agent workflow defined here: #file:docs/workflows/implement_feature_workflow_v1.md.
        For THIS specific task, the feature you need to implement is detailed in the following specification file: #file:docs/features/01_truck_vehicle_type.md. Treat this as your primary "#featureSpecFile" for this run.
        Remember to use the coding guidelines already specified within the generic workflow's system prompt (i.e., from docs/instructions/copilot_codegen_cpp_instructions.md).
        Please proceed.`
    4.  **Review Generated Code/Suggestions:** Carefully examine the content Copilot suggests for `Truck.h`, `Truck.cpp`, and any proposed modifications to `Vehicle.h`, `CMakeLists.txt`, and `main.cpp`. Apply these suggestions to your actual files in the editor.
        * **Build the Project:** Navigate to your build directory (e.g., `build`). Run `cmake ..` (or `cmake -S . -B build` from project root if build dir doesn't exist/is fresh) then `cmake --build .` (or `cmake --build build`).
        * Fix any build errors. You can ask Copilot for help: select the error message in the terminal, right-click and choose a Copilot "Explain/Fix" option, or copy the error into Chat and ask `@workspace /fix compile errors in [filename] based on this error: [paste error]`.
        * Does the implemented code adhere to the "Truck" feature spec and your C++ coding guidelines?
        * Is the logic for truck-specific behavior (if any implemented yet) correct?
    5.  **Refine (Example - using Edits mode or Inline Chat):**
        * Open `Truck.cpp`. Select the `Truck` constructor. Activate Edits Mode (pencil icon or `Cmd+E`/`Ctrl+E`): `Using the feature spec #file:docs/features/01_truck_vehicle_type.md, ensure all Truck member variables are initialized in the initializer list and the Vehicle base class constructor is called correctly.`
        * In `Truck.h`, select a member function. Activate Inline Chat (`Cmd+I` or `Ctrl+I`): `/doc Add Doxygen comment for this method, explaining its purpose as it relates to a Truck.`
        * If `Vehicle.h` needs a virtual destructor (and the agent didn't handle it or you want to verify): Open `Vehicle.h`, select the class name. In Chat, ask: `@workspace #file:src/Vehicle.h This class is a base class for Truck. Should it have a virtual destructor to ensure proper cleanup? If so, please provide the updated class definition with one.`
    6.  Iterate on review, build, and refinement until the "Truck" feature is implemented as per its specification and compiles cleanly.

---

## Section 5: Implementing and Testing with Guidelines

**Goal:** Generate and run unit tests for the newly implemented "Truck" feature using your chosen/configured testing framework (e.g., Google Test) and the defined testing guidelines.

---

### Exercise 5.1: Generate Unit Tests for `Truck` Class

* **Purpose:** To create unit tests for the `Truck` class, especially its constructor and any unique behaviors defined in its specification.
* **Aim:** Use the `/tests` command with your custom C++ test generation instructions.
* **Steps:**
    1.  Create a `tests` directory at the project root if it doesn't exist.
    2.  Manually create an empty file named `TruckTest.cpp` inside the `tests` directory.
    3.  Open the empty `TruckTest.cpp` in VS Code.
    4.  In Copilot Chat, ensure `Truck.h` and `Truck.cpp` are available for context (e.g., have them open or rely on `@workspace`). Then, with `TruckTest.cpp` as your active file, prompt:
        `@workspace #file:src/Truck.h #file:src/Truck.cpp #file:docs/features/01_truck_vehicle_type.md #file:docs/instructions/copilot_testgen_cpp_instructions.md
        /tests Populate this active test file (TruckTest.cpp) with Google Test (or your chosen framework's) unit tests for the Truck class.
        Focus on:
        1.  Constructor: Test that a Truck is initialized with its specific attributes (e.g., max speed, length) as defined in its feature specification.
        2.  If the Truck class has overridden methods (like `updateSpeed`) with distinct logic, test that behavior under relevant conditions described or implied by the spec.
        3.  Ensure tests adhere to the general and framework-specific guidelines in our test generation instructions document.`
    5.  Review the tests Copilot adds to `TruckTest.cpp`. Check for:
        * Correct syntax for your chosen testing framework (e.g., `TEST`, assertions for GTest).
        * Adherence to naming conventions from your instructions.
        * Meaningful test cases covering aspects from the "Truck" spec.
        * Necessary includes (like `gtest/gtest.h` and `Truck.h`).
    6.  Refine tests as needed using Copilot Chat or manual edits. Save the file.

### Exercise 5.2: Add Test Executable to CMake and Run Tests

* **Purpose:** To compile and execute the newly created unit tests.
* **Aim:** Modify `CMakeLists.txt` to build the test executable and then run it.
* **Steps:**
    1.  Open `CMakeLists.txt`.
    2.  In Copilot Chat, ask for guidance if needed (or refer to your testing framework integration from Section 3.2):
        `@workspace #file:CMakeLists.txt #file:tests/TruckTest.cpp I have a test file at tests/TruckTest.cpp using Google Test (or your chosen framework). How do I define a test executable named 'carSimTests' in CMake, link it against the testing framework (e.g., GTest::gtest_main), and ensure tests are discoverable by CTest? I've already set up the framework in CMake.`
    3.  Based on Copilot's suggestions (and your framework), add the necessary CMake commands. For Google Test, this would typically be:
        ```cmake
        # Example for adding the GTest test executable
        # Ensure this is after enable_testing() and FetchContent_MakeAvailable(googletest)
        if(TARGET GTest::gtest_main) # Check if GTest target is available
            add_executable(carSimTests tests/TruckTest.cpp src/Truck.cpp src/Vehicle.cpp) # Add sources needed for the test
            target_link_libraries(carSimTests PRIVATE GTest::gtest_main)
            # include(GoogleTest) # May not be needed if already included globally for tests
            gtest_discover_tests(carSimTests)
        else()
            message(WARNING "Google Test targets not available. Test executable 'carSimTests' will not be built.")
        endif()
        ```
        *Note: You might need to include `src/Vehicle.cpp` or other dependencies if `Truck.cpp` relies on them directly for the tests.*
    4.  Apply the changes to `CMakeLists.txt`.
    5.  **Build and Run Tests:**
        * Navigate to your build directory in the terminal (e.g., `cd build`).
        * Run `cmake ..` (to reconfigure).
        * Run `cmake --build .` (to compile everything, including tests).
        * Run `ctest` (from the build directory). This command should discover and run tests defined with `gtest_discover_tests` or similar mechanisms for other frameworks. Alternatively, you might run the test binary directly (e.g., `./tests/carSimTests` or `build/tests/carSimTests`).
    6.  Debug any failing tests with Copilot's help.

---

## Section 6: Refining Agent Workflows & Iterative Development

**Goal:** Improve the generic agent workflow based on experience and then use it to plan and implement another, more complex feature from the `README.md`.

---

### Exercise 6.1: Enhance Generic Agent Workflow (`implement_feature_workflow_v2.md`)

* **Purpose:** To make the generic agent workflow more robust and aligned with best practices based on your experience and requirements.
* **Aim:** Create `docs/workflows/implement_feature_workflow_v2.md` by refining v1.
* **Steps:**
    1.  Manually create an empty file named `docs/workflows/implement_feature_workflow_v2.md`.
    2.  Open this new file. Copy the content from `docs/workflows/implement_feature_workflow_v1.md` and paste it into `implement_feature_workflow_v2.md`.
    3.  Now, modify `implement_feature_workflow_v2.md`. Use Copilot Chat (with the file active) or Edits mode to help you incorporate the following refinements into the copied content:
        * **Refine System Prompt:**
            * Add: `"You must explicitly ask for permission via a clear question before deleting any existing code or performing significant refactorings not explicitly detailed in the #featureSpecFile. If you propose such changes, clearly explain your reasoning first and wait for user approval before proceeding with generating the refactored code."`
            * Add: `"When providing code for existing files, clearly differentiate new/modified code from existing code shown for context. For example, use comments like `// New code starts` / `// New code ends` or `// Modified block`."`
            * Add: `"DO NOT attempt to commit code to version control. DO NOT introduce any new third-party libraries unless they are explicitly part of the #featureSpecFile or pre-approved project dependencies."`
        * **Add New Workflow Step (Build & Test Execution Guidance - typically after step 5 'Modify Supporting Files'):**
            * `"X. Build and Test Execution Guidance: After all code modifications and additions are proposed, explicitly state the sequence of CMake commands the user should run from their build directory to reconfigure, build the entire project (including tests), and then execute the tests (e.g., 'cmake .. && cmake --build . && ctest'). Report if the build or tests are expected to fail due to the feature being incomplete or if there are known issues based on the work done in this pass."` (Adjust step number X accordingly).
        * **Add New Workflow Step (Documentation Impact Assessment - typically after Build & Test Guidance):**
            * `"Y. Documentation Impact Assessment: Review the implemented feature. If it has led to significant changes in the overall class structure, component interactions, or data flow that deviate from or substantially clarify the existing architecture (e.g., as might be visualized in `docs/architecture/SystemDiagram.md`), explicitly note this. Briefly describe what architectural documentation might need updating by the user to reflect these changes."` (Adjust step number Y accordingly).
    4.  Review the `implement_feature_workflow_v2.md` for clarity, logical flow, and completeness. Ensure it remains generic. Save the file.

### Exercise 6.2: Plan and Implement a More Complex Feature (e.g., "Dynamic Environmental Factors")

* **Purpose:** To apply the iterative development process (Spec -> Instructions -> Refined Agent Workflow -> Refinement) to a more challenging feature.
* **Aim:** Follow the full cycle for a new feature, using the refined `implement_feature_workflow_v2.md`.
* **Steps:**
    1.  **Choose Feature:** Select "Dynamic EnvironmentalFactors" from the project `README.md`'s "Explore with GitHub Copilot: Development Directions" section.
    2.  **Brainstorm & Specify:**
        * Use Copilot Chat to brainstorm how environmental factors (e.g., "Rain" that reduces vehicle maximum speed) could be modeled. Consider where this state would be managed (e.g., in the `Road` class, or a new `Environment` class).
        * Manually create a new empty feature specification file: `docs/features/02_environmental_factors.md`. Open it.
        * Use Copilot Chat (with the file active) or Edits mode to populate it. Prompt:
            `@workspace Populate this active file with a feature specification for 'Dynamic Environmental Factors'. Cover:
            - How factors (e.g., an enum `WeatherCondition { NORMAL, RAIN }`) are represented.
            - How the `Road` class might manage and update the current `WeatherCondition`.
            - How `Vehicle::updateSpeed` (or a related method) should be modified to consider the current weather (e.g., if `RAIN`, reduce effective max speed by a certain factor or amount).
            - Any impact on existing classes (`Vehicle`, `Road`, `main.cpp`) and whether any new classes/structs are needed.
            - How `main.cpp` might be modified to simulate changing weather conditions during the simulation loop.`
    3.  **(Optional) Update Custom Instructions:** If this feature introduces new C++ patterns (e.g., specific ways to handle state changes or events) not well-covered by your existing `docs/instructions/copilot_codegen_cpp_instructions.md`, consider jotting down these specific guidelines. For this exercise, the primary reliance will be on the main codegen file, but be mindful if new patterns emerge.
    4.  **Execute Refined Agent Workflow:**
        * **User Prerequisite from Workflow:** Based on your new `02_environmental_factors.md` spec, if it calls for new classes, manually create the empty `.h` and `.cpp` files in `src/` first.
        * In Copilot Chat, invoke your refined workflow. Example conceptual prompt:
            `@workspace Act as my AI C++ Developer assistant.
            Your task is to implement the new "Environmental Factors" feature.
            You must follow all instructions precisely from the generic agent workflow defined here: #file:docs/workflows/implement_feature_workflow_v2.md.
            For THIS specific task, the feature you need to implement is detailed in the following specification file: #file:docs/features/02_environmental_factors.md. Treat this as your primary "#featureSpecFile" for this run.
            Remember to use the coding guidelines already specified within the generic workflow's system prompt.
            Please proceed.`
    5.  **Review & Refine:**
        * Carefully review the code suggestions from Copilot for all affected files. Apply them to your editor.
        * Build the project using CMake as per the agent's guidance (or your standard build steps). Address any build errors with Copilot's assistance.
        * Use Copilot Edits/Inline Chat for refinements to logic, style, and comments, ensuring adherence to the spec and guidelines.
    6.  **Test:**
        * Manually create empty test files if new classes were introduced (e.g., `tests/EnvironmentTest.cpp`) or open existing ones to add tests (e.g., `tests/VehicleTest.cpp`, `tests/RoadTest.cpp`).
        * Use Copilot Chat (`/tests`) with your test guidelines (`#file:docs/instructions/copilot_testgen_cpp_instructions.md`) to generate tests for the new environmental factor logic. For example, test that a `Vehicle`'s speed is correctly limited when `WeatherCondition` is `RAIN`, or that the `Road` correctly updates/reports the current weather.
        * Add any new test source files to `CMakeLists.txt` and ensure they are part of a test executable.
        * Build and run tests using `ctest`.
    7.  **Documentation Check:** Based on the agent's "Documentation Impact Assessment" step from the workflow, consider if `docs/architecture/SystemDiagram.md` needs manual updating or if you can prompt Copilot to help generate an updated Mermaid snippet for the affected parts.

### Exercise 6.3: (Optional) Explore Devcontainer for C++ Environment Standardization

* **Purpose:** To learn about creating a consistent development environment for C++ projects using devcontainers.
* **Aim:** Use Copilot Chat to help generate a basic `.devcontainer/devcontainer.json` file.
* **Steps:**
    1.  If you don't have one, create a `.devcontainer` folder at the project root. Manually create an empty `devcontainer.json` file inside it. Open this file.
    2.  In Copilot Chat, with `devcontainer.json` active:
        `@workspace Populate this active devcontainer.json file for this C++ CMake project. It should specify a suitable base Docker image (e.g., from mcr.microsoft.com/devcontainers/cpp) that includes a C++17 compatible compiler (like g++), CMake, and Git. If possible through devcontainer features or a postCreateCommand, ensure tools for Google Test development are available. Also, list common C++ VS Code extensions that should be automatically installed in the container, such as Microsoft's C/C++ extension, CMake Tools, and GitHub Copilot itself.`
    3.  Review the generated `devcontainer.json`. You may need to research specific Docker images or devcontainer features to refine it further (e.g., specific versions, additional tools).
    4.  If you use Docker Desktop and have the "Dev Containers" VS Code extension installed, you can try using the Command Palette option "Dev Containers: Reopen in Container" to build and open your project in the defined environment. This can help ensure all participants have a consistent toolchain.

---