// src/cpu.cpp
//
// Copyright 2024 Daniel P. Teberian


/* IMPORTS */
#include <cstdint>


// CPU class
class CPU
{
    private:
    /* REGISTERS */

    uint8_t A; // Accumulator
    uint8_t F; // Flags
    uint8_t B; // B register
    uint8_t C; // C register
    uint8_t D; // D register
    uint8_t E; // E register
    uint8_t H; // H register
    uint8_t L; // L register

    uint16_t SP; // Stack pointer
    uint16_t PC; // Program counter

    uint8_t memory[65536]; // Memory
    // Set memory size to 65536 bytes (64KB)

    
    // Read memory
    uint8_t read(uint16_t address)
    {
        // If the address is less than the memory size
        if (address < sizeof(memory))
        {
            // Return the value of memory, at the address specified
            return memory[address];
        }
        else
        {
            // TODO: Handle out-of-bounds memory access
            return 0;
        }
    }

    // Write memory
    void write(uint16_t address, uint8_t value)
    {
        // If the address is less the memory size
        if (address < sizeof(memory))
        {
            // Set the value of memory, at the address, to "value"
            memory[address] = value;
        }
        else
        {
            // TODO: Add something here. Maybe an error message, definitely show up in the debug log.
        }
    }

    // Execute opcode
    void execop(uint8_t opcode)
    {
        switch(opcode)
        {
            /* OPCODES IMPLEMENTATION */

            // NOP (No operation)
            case 0x00:
                break;
            
            // Unknown opcode/undefined behavior
            default:
                break;
        }
    }


    public:
        CPU()
        {
            /* CPU initialization */

            A = 0; // Set accumulator to 0
            F = 0; // Set flags to 0
            B = 0; // Set B register to 0
            C = 0; // Set C register to 0
            D = 0; // Set D register to 0
            E = 0; // Set E register to 0
            H = 0; // Set H register to 0
            L = 0; // Set L register to 0

            // Set stack pointer value to default starter value
            SP = 0xFFFe;

            // Set program counter to address where most ROMs begin
            PC = 0x0100;

            // Initialize memory to 0
            for (int i = 0; i < 65536; ++i)
            {
                memory[i] = 0;
            }
        }

        // Get and run next instruction (seek and run)
        void SAR()
        {
            // Fetch opcode from the memory at program counter
            uint8_t opcode = read(PC);

            // Increment program counter by 1
            PC++;

            // Execute opcode
            execop(opcode);
        }
};


// main function
int main()
{
    // Create CPU, using CPU class
    CPU cpu;

    return 0;
}