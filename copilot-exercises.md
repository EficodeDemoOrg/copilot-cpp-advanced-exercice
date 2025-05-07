# GitHub Copilot Exercises: Specification-Driven Development & Customization (C++ Car Simulation)

**Session Goal:** Learn to effectively guide and customize GitHub Copilot for extending a C++ project. This session focuses on planning with AI, defining detailed specifications and guidelines (code style, quality, testing, architectural consistency), creating reusable prompts, defining and refining agent workflows, and iteratively developing features based on these structured inputs.

**Project Context:** We start with the existing "Car Simulation" C++ project. It includes a basic `Vehicle` class, a `Road` class, a `main.cpp` to run a simple simulation, and a `CMakeLists.txt` for building. The goal is to extend this simulation with new features.

**Key Customization Mechanisms & Copilot Features:**

* **Workspace Contextual Understanding:** Copilot's ability to use open files and workspace content (`@workspace` in chat).
* **Workspace Instructions (`.github/copilot-instructions.md`):** Persistent, high-level context about the project, technologies, and overall goals.
* **Custom Instructions (VS Code Settings / Referenced Files):** Specific guidelines for Copilot's behavior during code generation, test generation, explanations, etc. Often configured via `settings.json` by referencing external `.md` instruction files (e.g., from a `docs/instructions/` folder).
* **Reusable Prompts (`*.prompt.md`):** Parameterized instructions for common, well-defined, limited-scope tasks, invokable in chat.
* **Agent Workflow Instructions (Separate `.md` File):** Detailed, multi-step instructions to guide Copilot (especially in agent-like interactions or complex chat sequences) through more complex tasks like implementing a feature based on a specification.
* **Copilot Chat Features:**
    * `@workspace` for broad context.
    * `#file:` references for specific file context.
    * `/explain`, `/fix`, `/tests`, `/new`, `/doc` commands.
    * Edits Mode (pencil icon or `Cmd+E`/`Ctrl+E`) for focused code modifications.
    * Inline Chat (`Cmd+I`/`Ctrl+I`) for quick, in-editor interactions.

**Prerequisites:**

* Familiarity with basic Copilot Chat features from any previous introductory sessions.
* A C++17 compatible compiler (e.g., GCC, Clang, MSVC).
* CMake (version 3.10 or higher).
* Git and a Git client.
* VS Code with the latest GitHub Copilot and GitHub Copilot Chat extensions enabled.
* A basic understanding of C++ and CMake.
* Knowledge of how to access and modify VS Code workspace settings (`.vscode/settings.json`).

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
* **Aim:** Create the `.github/copilot-instructions.md` file with essential project information.
* **Steps:**
    1.  Create a folder named `.github` at the root of your project if it doesn't exist.
    2.  Inside `.github`, create a file named `copilot-instructions.md`.
    3.  Use Copilot Chat (or your own knowledge) to populate this file. Prompt example:
        `@workspace /new #.github/copilot-instructions.md Create initial Copilot instructions for this C++ car simulation project. Include: Project overview (C++17 car simulation on a circular road, built with CMake), Core Technologies (C++17, CMake), and Initial Architectural Ideas (Vehicle class for state/movement, Road class manages vehicles, simulation loop in main). Also mention that the project aims for modular and extensible design.`
    4.  Review and save the generated `copilot-instructions.md`.
    5.  **(Verification):** In Copilot Chat, ask `@workspace What C++ standard is this project intended to use?` Copilot should ideally pick this up from your instructions.

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
* **Aim:** Use Copilot Chat with Edits mode to generate the content for `docs/features/01_truck_vehicle_type.md`.
* **Steps:**
    1.  Create a folder `docs` at the project root if it doesn't exist. Inside `docs`, create another folder `features`.
    2.  Create an empty file: `docs/features/01_truck_vehicle_type.md`.
    3.  Open this empty file. Then, in Copilot Chat, use a prompt targeting this file (e.g., by having it active or using `#file` reference if supported for `/new` or edits on empty files, otherwise copy-paste). A comprehensive prompt:
        `@workspace #file:docs/features/01_truck_vehicle_type.md /explain Generate a detailed feature specification in Markdown format for adding a 'Truck' vehicle type to our C++ Car Simulation. The Truck should inherit from the 'Vehicle' class. Based on our earlier discussion (slower acceleration, lower max speed, potentially longer length affecting spacing), cover these sections:
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
    4.  Use Copilot Chat's suggestion (possibly via Edits mode or by inserting into the file) to populate `01_truck_vehicle_type.md`. Review and refine the generated specification for clarity, completeness, and correctness. Ensure it aligns with the project's current state.

### Exercise 2.3: (Optional) Validate Feature Specification

* **Purpose:** To critically assess the generated feature specification.
* **Aim:** Simulate a validation step for the feature specification.
* **Steps:**
    1.  Read through the `docs/features/01_truck_vehicle_type.md` you just created.
    2.  In Copilot Chat, you could try:
        `@workspace #file:docs/features/01_truck_vehicle_type.md Review this feature specification. Does it seem complete for a first iteration of adding a Truck type? Are there any obvious contradictions or missing considerations based on the existing Vehicle and Road classes? What are potential challenges in implementing this?`
    3.  Consider Copilot's feedback as if it were from another developer or an AI quality check. Update your specification if necessary.

### Exercise 2.4: Update/Generate Architectural Diagram

* **Purpose:** To visualize how the new "Truck" class fits into the existing architecture.
* **Aim:** Use Copilot Chat to generate/update a Mermaid class diagram.
* **Steps:**
    1.  Create a folder `docs/architecture/` if it doesn't exist.
    2.  Open Copilot Chat. Prompt:
        `@workspace Based on the existing classes (Vehicle, Road, Main) and the feature specification for adding a 'Truck' class that inherits from 'Vehicle' (#file:docs/features/01_truck_vehicle_type.md), generate a Mermaid class diagram description. Show inheritance and key relationships.`
    3.  Copy the generated ```mermaid ... ``` block.
    4.  Create/open a file like `docs/architecture/SystemDiagram.md`.
    5.  Paste the Mermaid block into this file. If you have a Mermaid preview extension in VS Code, check the diagram.

---

## Section 3: Defining Copilot Customization & Guidelines for C++

**Goal:** Configure Copilot's behavior for C++ code generation and testing by creating custom instruction files and referencing them in VS Code settings.

---

### Exercise 3.1: Define Custom C++ Code Generation Instructions

* **Purpose:** To guide Copilot towards generating C++ code that meets specific project standards.
* **Aim:** Create `docs/instructions/copilot_codegen_cpp_instructions.md` and reference it.
* **Steps:**
    1.  Create `docs/instructions/` folder if it doesn't exist.
    2.  Inside `docs/instructions/`, create `copilot_codegen_cpp_instructions.md`.
    3.  Add C++ specific guidelines. Prompt Copilot Chat for help or write them:
        `@workspace /new #docs/instructions/copilot_codegen_cpp_instructions.md Create a Markdown file with C++ code generation guidelines for this project. Include sections for:
        - **C++ Standard:** Adhere to C++17.
        - **Header Files:** Use #pragma once for header guards. Include necessary headers only. Prefer forward declarations where possible in .h files. Order includes: project-specific, then system/library.
        - **Class Design:** Declare destructors virtual in base classes if they are meant to be inherited and objects deleted via base pointer. Initialize members in constructor initializer lists. Use 'const' correctness thoroughly for member functions and parameters. Mark member functions that do not modify object state as 'const'.
        - **Memory Management:** Use smart pointers (std::shared_ptr, std::unique_ptr) where ownership is involved. Avoid raw 'new'/'delete' unless absolutely necessary and well-justified. (The current project uses std::shared_ptr for Vehicles in Road).
        - **Commenting:** Use Doxygen-style comments for classes, methods, and complex code blocks (e.g., `/** ... */` or `///`).
        - **Error Handling:** For now, prefer simple error messages to std::cerr or exceptions for critical unrecoverable errors. Avoid `exit()` in library-like code.
        - **Naming Conventions:** Use PascalCase for class names (e.g., `MyClass`), camelCase for member variables and functions (e.g., `myVariable`, `myFunction`).`
    4.  Save the file.
    5.  **Open Workspace Settings (JSON):** Command Palette (`Ctrl+Shift+P` or `Cmd+Shift+P`) -> `Preferences: Open Workspace Settings (JSON)`.
    6.  **Reference Instruction File:** Add the setting to reference your instruction file. The exact key might vary with Copilot versions; consult current documentation. Example:
        ```json
        {
          // ... other settings ...
          "github.copilot.chat.codeGeneration.instructions": [ // Or a similar key
            {
              "file": "docs/instructions/copilot_codegen_cpp_instructions.md"
            }
          ]
        }
        ```
    7.  Save `settings.json`.

### Exercise 3.2: Plan for Testing & Define Test Generation Instructions

* **Purpose:** To set up a testing framework (Google Test) and define guidelines for generating tests.
* **Aim:** Add GTest to `CMakeLists.txt` and create `docs/instructions/copilot_testgen_cpp_instructions.md`.
* **Steps - Part A: Add Google Test to CMake**
    1.  Open `CMakeLists.txt`.
    2.  In Copilot Chat, ask for help:
        `@workspace #file:CMakeLists.txt Show me how to add Google Test to this project using CMake's FetchContent module. I want to be able to link my test executables against GTest.`
    3.  Review Copilot's suggestions (it should involve `WorkspaceContent_Declare`, `WorkspaceContent_MakeAvailable`, and linking `gtest_main`). Carefully apply the changes to your `CMakeLists.txt`. This might involve:
        ```cmake
        # Near the top
        include(FetchContent)

        # For GTest
        FetchContent_Declare(
          googletest
          GIT_REPOSITORY [https://github.com/google/googletest.git](https://github.com/google/googletest.git)
          GIT_TAG    release-1.14.0 # Or a more recent stable tag
        )
        FetchContent_MakeAvailable(googletest)
        ```
        And later, for a test executable: `target_link_libraries(your_test_executable PRIVATE GTest::gtest_main)` and `include(GoogleTest)`
    4.  It's also good practice to enable testing: `enable_testing()` and `gtest_discover_tests(your_test_executable)`.
* **Steps - Part B: Create Test Generation Instructions**
    1.  Create `docs/instructions/copilot_testgen_cpp_instructions.md`.
    2.  Populate it. Prompt example:
        `@workspace /new #docs/instructions/copilot_testgen_cpp_instructions.md Create guidelines for generating C++ unit tests using Google Test. Include:
        - **Framework:** Use Google Test (`gtest/gtest.h`).
        - **Test Cases:** Use `TEST(TestSuiteName, TestName) { ... }`.
        - **Assertions:** Use GTest assertion macros (e.g., `ASSERT_EQ`, `EXPECT_TRUE`, `ASSERT_THROW`).
        - **Naming:** `TestSuiteName` should be the class being tested (e.g., `VehicleTest`). `TestName` should describe the specific scenario (e.g., `AcceleratesWhenSpaceIsClear`).
        - **Structure:** Clearly set up test preconditions (Arrange), execute the code under test (Act), and verify results (Assert). Comment these sections if complex.
        - **Fixtures:** Use test fixtures (`class MyFixture : public ::testing::Test`) for shared setup/teardown logic if needed.
        - **Coverage:** Aim for testing public interfaces and significant logic paths.`
    3.  Save the file.
    4.  **Open Workspace Settings (JSON)** and add/modify the setting for test generation instructions, referencing your new file. Example key (check docs):
        ```json
        {
          // ... other settings ...
          "github.copilot.tests.instructions": [ // Or a similar key for the /tests command
            {
              "file": "docs/instructions/copilot_testgen_cpp_instructions.md"
            }
          ]
        }
        ```
    5.  Save `settings.json`.

---

## Section 4: Guided Feature Implementation & Agent Workflow Creation

**Goal:** Implement the "Truck" feature, partly through direct Copilot interaction and partly by defining and using an initial agent workflow.

---

### Exercise 4.1: Create Reusable Prompt (C++ Class Stub)

* **Purpose:** To create a reusable way to generate a basic C++ class definition and implementation file stub.
* **Aim:** Create a `.prompt.md` file for generating a C++ class stub.
* **Steps:**
    1.  Create a `.prompts` folder at the project root if it doesn't exist.
    2.  Create `.prompts/cpp_class_stub.prompt.md` with content like:
        ```markdown
        ---
        name: C++ Class Stub
        description: Generates stubs for a C++ header (.h) and source (.cpp) file for a new class.
        variables:
          - name: className
            description: The name of the class (e.g., Truck).
            required: true
          - name: baseClassName
            description: (Optional) The name of the base class it inherits from.
            required: false
          - name: headerFilePath
            description: Desired path for the .h file (e.g., src/Truck.h).
            required: true
          - name: sourceFilePath
            description: Desired path for the .cpp file (e.g., src/Truck.cpp).
            required: true
        ---

        For class `{{className}}`:

        **1. Header File (`{{headerFilePath}}`):**
        Create the content for `{{headerFilePath}}`.
        - Include `#pragma once`.
        {{#if baseClassName}}
        - Include the header for `{{baseClassName}}` (assume it's `{{baseClassName}}.h` in the same directory or a known project path).
        - Declare `{{className}}` inheriting publicly from `{{baseClassName}}`.
        {{else}}
        - Declare `{{className}}`.
        {{/if}}
        - Add a public default constructor declaration.
        {{#if baseClassName}}
        - Add a public virtual destructor (override if base has one).
        {{else}}
        - Add a public virtual destructor.
        {{/if}}
        - Add a private section for member variables (leave empty for now).
        - Ensure it adheres to project coding guidelines (e.g., Doxygen-style class comment stub).

        **2. Source File (`{{sourceFilePath}}`):**
        Create the content for `{{sourceFilePath}}`.
        - Include the header `{{className}}.h`.
        - Provide empty definitions for the default constructor and destructor.
        - Ensure it adheres to project coding guidelines.
        ```
    3.  Save the file.
    4.  **(Verification):** In Copilot Chat, try invoking it: `# (select .prompts/cpp_class_stub.prompt.md)`. Provide `Truck` for className, `Vehicle` for baseClassName, `src/Truck.h` and `src/Truck.cpp` for paths. Review the suggested file contents. Don't apply yet, or apply to temporary files.

### Exercise 4.2: Define Initial Agent Workflow for Feature Implementation

* **Purpose:** To create a structured set of instructions for Copilot to implement the "Truck" feature based on its specification.
* **Aim:** Create `docs/workflows/implement_truck_feature_v1.md`.
* **Steps:**
    1.  Create `docs/workflows/` folder if it doesn't exist.
    2.  Create `docs/workflows/implement_truck_feature_v1.md`.
    3.  Add content to guide the agent. Example:
        ```markdown
        # AI Agent Workflow: Implement Truck Feature (v1)

        ## System Prompt
        You are a C++ developer tasked with implementing the 'Truck' vehicle type feature for a car simulation project.
        Adhere strictly to the provided feature specification, project coding guidelines (from referenced `copilot_codegen_cpp_instructions.md`), and existing architectural patterns.
        Use C++17.

        ## Input Variables
        - `#specFile`: Reference to the feature specification (e.g., `#docs/features/01_truck_vehicle_type.md`).
        - `#codegenInstructions`: Reference to C++ code generation guidelines (e.g., `#docs/instructions/copilot_codegen_cpp_instructions.md`).
        - `#workspace`: Access to the workspace code.

        ## Workflow Steps
        1.  **Understand Requirements:** Read and analyze the `#specFile`.
        2.  **Create Files:**
            * Create `src/Truck.h` and `src/Truck.cpp`. Use the `#prompts/cpp_class_stub.prompt.md` with className=Truck, baseClassName=Vehicle, and appropriate paths to generate initial stubs.
            * Alternatively, generate the class structure directly based on the spec and codegen instructions.
        3.  **Implement `Truck.h`:**
            * Define the `Truck` class inheriting from `Vehicle`.
            * Add member variables specified (e.g., for custom speed/acceleration, length) with appropriate access specifiers.
            * Declare constructor(s) as per spec (e.g., taking initial position, and truck-specific attributes or using defaults).
            * Declare any overridden methods from `Vehicle` (e.g., `updateSpeed` if its logic needs to be specialized, or add new methods specific to Truck). Add `override` keyword.
            * Ensure Doxygen comments and adherence to `#codegenInstructions`.
        4.  **Implement `Truck.cpp`:**
            * Implement the constructor(s), initializing base class and Truck-specific members.
            * Implement any overridden or new methods. For example, if `updateSpeed` is overridden, implement its logic considering the truck's unique properties.
            * Adhere to `#codegenInstructions`.
        5.  **Modify `Vehicle.h` (If Necessary):**
            * Check if `Vehicle.h` needs changes for proper inheritance (e.g., `virtual` destructor if not already present, `protected` members if `Truck` needs access). Propose changes if needed, explaining why.
        6.  **Modify `CMakeLists.txt`:**
            * Add `src/Truck.cpp` to the `add_executable` command or source list variable.
        7.  **Modify `main.cpp` (Basic Instantiation):**
            * Include `Truck.h`.
            * In `main`, instantiate one or two `Truck` objects and add them to the `Road` to demonstrate they can be created and managed.
        8.  **Build Check (Conceptual):** At this stage, ensure the code *should* compile. (Actual build test comes later in a refined workflow).
        9.  **Report:** List all files created or modified. Note any parts of the spec not fully implemented or areas for future refinement. Identify any deviations from the spec.
        ```
    4.  Save the file.

### Exercise 4.3: Execute Agent Workflow & Refine Code

* **Purpose:** To use the defined workflow to generate the "Truck" feature code and then iteratively refine it.
* **Aim:** Invoke the agent workflow, review the generated C++ code, and use Copilot's Edits/Inline Chat for improvements.
* **Steps:**
    1.  Ensure all referenced documents (`#specFile`, `#codegenInstructions`, `#prompts/cpp_class_stub.prompt.md`) exist and are accessible.
    2.  In Copilot Chat, invoke the workflow. The exact invocation depends on how you structure the prompt for an "agent" persona if Copilot doesn't have a formal agent mode yet. You might copy-paste the workflow content into the chat, or reference it if that feature is robust. Example conceptual prompt:
        `@workspace Act as an AI agent. Follow the instructions in #docs/workflows/implement_truck_feature_v1.md.
        Use #docs/features/01_truck_vehicle_type.md as the #specFile.
        Use #docs/instructions/copilot_codegen_cpp_instructions.md as the #codegenInstructions.
        Use #.prompts/cpp_class_stub.prompt.md as #prompts/cpp_class_stub.prompt.md.
        Proceed with implementing the Truck feature.`
    3.  **Review Generated Code:** Carefully examine `Truck.h`, `Truck.cpp`, `CMakeLists.txt`, and `main.cpp`.
        * Does the code compile (try `cmake ..` and `cmake --build .` in your build directory)? Fix any build errors, possibly with Copilot's help (`@workspace /fix compile errors in Truck.cpp`).
        * Does it adhere to the feature spec and coding guidelines?
        * Is the logic for truck-specific behavior (if any implemented yet) correct?
    4.  **Refine (Example - using Edits mode or Inline Chat):**
        * Select the `Truck` constructor in `Truck.cpp`. Use Edits Mode: `Ensure all member variables are initialized in the initializer list and the base class constructor is called correctly.`
        * In `Truck.h`, select a member function. Use Inline Chat (`Cmd+I` or `Ctrl+I`): `/doc Add Doxygen comment for this method.`
        * If `Vehicle.h` wasn't updated with a virtual destructor, ask Copilot: `@workspace #file:src/Vehicle.h Does this class need a virtual destructor if it's a base class? If so, add one.`
    5.  Iterate on review, build, and refinement until the basic Truck feature is implemented as per spec.

---

## Section 5: Implementing and Testing with Guidelines (Google Test)

**Goal:** Generate and run unit tests for the new "Truck" feature using Google Test and the defined testing guidelines.

---

### Exercise 5.1: Generate Unit Tests for `Truck` Class

* **Purpose:** To create unit tests for the `Truck` class, especially its constructor and any unique behaviors.
* **Aim:** Use the `/tests` command with the custom C++ test generation instructions.
* **Steps:**
    1.  Create a `tests` directory at the project root.
    2.  Create a file like `tests/TruckTest.cpp`.
    3.  In Copilot Chat, with `Truck.h` (and `Truck.cpp`) in your workspace context:
        `@workspace #file:src/Truck.h #file:src/Truck.cpp /tests #file:tests/TruckTest.cpp Generate Google Test unit tests for the Truck class. Focus on:
        1.  Constructor: Test that a Truck is initialized with its specific attributes (e.g., max speed, if different from a generic Vehicle).
        2.  If Truck has overridden methods like `updateSpeed` with distinct logic, test that behavior.
        3.  Ensure tests adhere to the guidelines in #docs/instructions/copilot_testgen_cpp_instructions.md.`
    4.  Review the generated `TruckTest.cpp`. Check for:
        * Correct GTest syntax (`TEST`, assertions).
        * Adherence to naming conventions from your instructions.
        * Meaningful test cases covering aspects from the spec.
    5.  Refine tests as needed using Copilot Chat or manual edits.

### Exercise 5.2: Add Test Executable to CMake and Run Tests

* **Purpose:** To compile and execute the newly created unit tests.
* **Aim:** Modify `CMakeLists.txt` to build the test executable and then run it.
* **Steps:**
    1.  Open `CMakeLists.txt`.
    2.  In Copilot Chat, ask for guidance if needed:
        `@workspace #file:CMakeLists.txt #file:tests/TruckTest.cpp I have a GTest file at tests/TruckTest.cpp. How do I define a test executable named 'carSimTests' in CMake, link it against GTest::gtest_main, and ensure tests are discoverable by CTest? Remember I've already set up FetchContent for Google Test.`
    3.  Copilot should suggest something like:
        ```cmake
        # Add this after FetchContent_MakeAvailable(googletest) and enable_testing()
        if(TARGET GTest::gtest_main)
            add_executable(carSimTests tests/TruckTest.cpp)
            target_link_libraries(carSimTests PRIVATE GTest::gtest_main) # Link against gtest_main
            include(GoogleTest)
            gtest_discover_tests(carSimTests)
        endif()
        ```
    4.  Apply the changes to `CMakeLists.txt`.
    5.  **Build and Run Tests:**
        * Navigate to your build directory in the terminal.
        * Run `cmake ..` (to reconfigure).
        * Run `cmake --build .` (to compile everything, including tests).
        * Run `ctest` or `./tests/carSimTests` (or `build/tests/carSimTests` depending on your setup) to execute the tests.
    6.  Debug any failing tests with Copilot's help.

---

## Section 6: Refining Agent Workflows & Iterative Development

**Goal:** Improve the agent workflow based on experience and then use it to plan and implement another, more complex feature from the `README.md`.

---

### Exercise 6.1: Enhance Agent Workflow (`implement_feature_workflow_v2.md`)

* **Purpose:** To make the agent workflow more robust and aligned with best practices.
* **Aim:** Create `docs/workflows/implement_feature_workflow_v2.md` with refinements.
* **Steps:**
    1.  Copy `docs/workflows/implement_truck_feature_v1.md` to `docs/workflows/implement_feature_workflow_v2.md`.
    2.  Modify `implement_feature_workflow_v2.md`. Add/Refine the following based on the user's original requirements:
        * **System Prompt Enhancement:** "You must ask for permission before deleting any existing code or performing significant refactoring not explicitly stated in the feature spec. If you propose such changes, explain your reasoning clearly."
        * **New Workflow Step (Build & Test):** "After generating/modifying code, specify the CMake commands to build the project and run any relevant tests (e.g., `cmake --build .` in the build dir, then `ctest`). Report if the build or tests are expected to fail due to incomplete implementation or known issues."
        * **New Workflow Step (Documentation Update):** "If the feature implementation leads to changes in the overall architecture (e.g., new class interactions not obvious from the spec), note that `docs/architecture/SystemDiagram.md` (or relevant architectural docs) might need updating and briefly describe the change."
        * **Explicit Negative Constraints:** "DO NOT commit code to version control. DO NOT introduce third-party libraries not already approved or specified."
        * **Clarity on Existing Code:** "When modifying existing files, clearly indicate which parts are new additions or modifications versus existing code you are showing for context."
    3.  Save the refined workflow.

### Exercise 6.2: Plan and Implement a More Complex Feature (e.g., "Dynamic Environmental Factors")

* **Purpose:** To apply the iterative development process (Spec -> Instructions -> Agent Workflow -> Refinement) to a more challenging feature.
* **Aim:** Follow the full cycle for a new feature, using the refined `implement_feature_workflow_v2.md`.
* **Steps:**
    1.  **Choose Feature:** Select "Dynamic EnvironmentalFactors" from the `README.md` extensions.
    2.  **Brainstorm & Specify:**
        * Use Copilot Chat to brainstorm how environmental factors (e.g., "Rain" affecting max speed) could be modeled.
        * Create a new feature specification: `docs/features/02_environmental_factors.md`. Prompt Copilot to help draft it, covering:
            * How factors are represented (e.g., an enum, a class `Environment`).
            * How `Road` or `Vehicle` objects access current environmental conditions.
            * How `Vehicle::updateSpeed` logic changes based on the environment (e.g., rain reduces effective max speed).
            * Impact on existing classes and new components.
    3.  **(Optional) Update Custom Instructions:** If this feature requires new coding patterns not covered, update `docs/instructions/copilot_codegen_cpp_instructions.md`.
    4.  **Execute Refined Agent Workflow:**
        * In Copilot Chat, invoke the `implement_feature_workflow_v2.md`, providing the new `#specFile` (`#docs/features/02_environmental_factors.md`) and other relevant instruction files.
    5.  **Review & Refine:**
        * Critically review the code generated by the "agent."
        * Build the project.
        * Use Copilot Edits/Inline Chat for refinements.
    6.  **Test:**
        * Create `tests/EnvironmentTest.cpp` or update `VehicleTest.cpp` / `RoadTest.cpp`.
        * Use Copilot Chat (`/tests`) with your test guidelines to generate tests for the new environmental factor logic.
        * Add to CMake, build, and run tests.
    7.  **Documentation:** If the architecture diagram changed significantly, ask Copilot to help update the Mermaid description in `docs/architecture/SystemDiagram.md`.

### Exercise 6.3: (Optional) Explore Devcontainer for C++ Environment Standardization

* **Purpose:** To learn about creating a consistent development environment for C++ projects using devcontainers.
* **Aim:** Use Copilot Chat to help generate a basic `devcontainer.json` file.
* **Steps:**
    1.  In Copilot Chat, ask:
        `@workspace Can you help me create a basic .devcontainer/devcontainer.json file for this C++ CMake project? It should include a C++17 compatible compiler (like g++), CMake, Git, and the GTest dependencies if possible. Also include common C++ VS Code extensions like Microsoft's C/C++, CMake Tools, and GitHub Copilot.`
    2.  Review the generated `devcontainer.json`.
    3.  If you use Docker and have the "Dev Containers" VS Code extension, you can try reopening the project in the container.

---