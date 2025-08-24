
# Basic Logic Gates in LTspice

This folder contains LTspice schematic (`.asc`) and symbol (`.asy`) files for basic logic gates (AND, OR, NOT, NAND, NOR) and a custom function gate, along with their testbenches.

## Requirements
- LTspice 17.1.15 (Windows version) or compatible

## File Overview

| Gate      | Schematic      | Symbol      | Testbench             |
|-----------|----------------|-------------|-----------------------|
| AND       | and.asc        | and.asy     | testbench-and.asc     |
| OR        | or.asc         | or.asy      | testbench-or.asc      |
| NOT       | not.asc        | not.asy     | testbench-not.asc     |
| NAND      | nand.asc       | nand.asy    | testbench-nand.asc    |
| NOR       | nor.asc        | nor.asy     | testbench-nor.asc     |
| Function  | fun_g.asc      | fun_g.asy   | testbench-fun-g.asc   |

## How to Use


1. **Open and Simulate a Gate:**
	- To simulate a gate, open the corresponding testbench file (e.g., `testbench-and.asc`) in LTspice.
	- Click the Run (Simulate) button to view the logic gate's behavior.

2. **Edit or Reuse Gates:**
	- You can open the gate schematic files (e.g., `and.asc`) to inspect or modify the gate design.
	- Use the provided symbols in your own LTspice projects.

3. **Use This Folder as a Workspace for Custom Simulations:**
	- To create your own custom simulation using the gates provided here:
	  1. In LTspice, create a new schematic.
	  2. Save the new schematic file directly into this workspace folder.
	  3. When adding a component symbol in LTspice, in the "Select Component Symbol" dialog, set the top directory to this workspace folder.
	  4. All custom gate symbols (`.asy` files) in this folder will now be listed and available to add to your schematic.
	  5. Add the desired gates, wire them up, and run your simulation as usual.
	- This approach keeps all your custom designs and symbols together, making it easy to manage and reuse components.

## Example

To simulate an AND gate:
1. Open `testbench-and.asc` in LTspice.
2. Click the Run button (the "Running Man" icon).
3. View the output waveform to verify AND gate operation.

Repeat the above steps for other gates using their respective testbench files.

## Notes
- The testbench files are set up to demonstrate the function of each gate.
- The custom function gate (`fun_g.asc`, `fun_g.asy`) is an example of a user-defined logic function.
