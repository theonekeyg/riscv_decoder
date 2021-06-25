#ifndef RISCV_INSN_H
#define RISCV_INSN_H

#include <iostream>

enum InstructionType {
  INSN_R,
  INSN_I,
  INSN_S,
  INSN_B,
  INSN_U,
  INSN_J,
  INSN_UNDEFINED
};

static const enum InstructionType OPCODE_TYPES_TABLE[] = {
  /* 0b0000000 */ INSN_UNDEFINED,
  /* 0b0000001 */ INSN_UNDEFINED,
  /* 0b0000010 */ INSN_UNDEFINED,
  /* 0b0000011 */ INSN_I,
  /* 0b0000100 */ INSN_UNDEFINED,
  /* 0b0000101 */ INSN_UNDEFINED,
  /* 0b0000110 */ INSN_UNDEFINED,
  /* 0b0000111 */ INSN_UNDEFINED,
  /* 0b0001000 */ INSN_UNDEFINED,
  /* 0b0001001 */ INSN_UNDEFINED,
  /* 0b0001010 */ INSN_UNDEFINED,
  /* 0b0001011 */ INSN_UNDEFINED,
  /* 0b0001100 */ INSN_UNDEFINED,
  /* 0b0001101 */ INSN_UNDEFINED,
  /* 0b0001110 */ INSN_UNDEFINED,
  /* 0b0001111 */ INSN_I,
  /* 0b0010000 */ INSN_UNDEFINED,
  /* 0b0010001 */ INSN_UNDEFINED,
  /* 0b0010010 */ INSN_UNDEFINED,
  /* 0b0010011 */ INSN_I,
  /* 0b0010100 */ INSN_UNDEFINED,
  /* 0b0010101 */ INSN_UNDEFINED,
  /* 0b0010110 */ INSN_UNDEFINED,
  /* 0b0010111 */ INSN_UNDEFINED,
  /* 0b0011000 */ INSN_UNDEFINED,
  /* 0b0011001 */ INSN_UNDEFINED,
  /* 0b0011010 */ INSN_UNDEFINED,
  /* 0b0011011 */ INSN_UNDEFINED,
  /* 0b0011100 */ INSN_UNDEFINED,
  /* 0b0011101 */ INSN_UNDEFINED,
  /* 0b0011110 */ INSN_UNDEFINED,
  /* 0b0011111 */ INSN_UNDEFINED,
  /* 0b0100000 */ INSN_UNDEFINED,
  /* 0b0100001 */ INSN_UNDEFINED,
  /* 0b0100010 */ INSN_UNDEFINED,
  /* 0b0100011 */ INSN_S,
  /* 0b0100100 */ INSN_UNDEFINED,
  /* 0b0100101 */ INSN_UNDEFINED,
  /* 0b0100110 */ INSN_UNDEFINED,
  /* 0b0100111 */ INSN_UNDEFINED,
  /* 0b0101000 */ INSN_UNDEFINED,
  /* 0b0101001 */ INSN_UNDEFINED,
  /* 0b0101010 */ INSN_UNDEFINED,
  /* 0b0101011 */ INSN_UNDEFINED,
  /* 0b0101100 */ INSN_UNDEFINED,
  /* 0b0101101 */ INSN_UNDEFINED,
  /* 0b0101110 */ INSN_UNDEFINED,
  /* 0b0101111 */ INSN_UNDEFINED,
  /* 0b0110000 */ INSN_UNDEFINED,
  /* 0b0110001 */ INSN_UNDEFINED,
  /* 0b0110010 */ INSN_UNDEFINED,
  /* 0b0110011 */ INSN_R,
  /* 0b0110100 */ INSN_UNDEFINED,
  /* 0b0110101 */ INSN_UNDEFINED,
  /* 0b0110110 */ INSN_U,
  /* 0b0110111 */ INSN_U,
  /* 0b0111000 */ INSN_UNDEFINED,
  /* 0b0111001 */ INSN_UNDEFINED,
  /* 0b0111010 */ INSN_UNDEFINED,
  /* 0b0111011 */ INSN_UNDEFINED,
  /* 0b0111100 */ INSN_UNDEFINED,
  /* 0b0111101 */ INSN_UNDEFINED,
  /* 0b0111110 */ INSN_UNDEFINED,
  /* 0b0111111 */ INSN_UNDEFINED,
  /* 0b1000000 */ INSN_UNDEFINED,
  /* 0b1000001 */ INSN_UNDEFINED,
  /* 0b1000010 */ INSN_UNDEFINED,
  /* 0b1000011 */ INSN_UNDEFINED,
  /* 0b1000100 */ INSN_UNDEFINED,
  /* 0b1000101 */ INSN_UNDEFINED,
  /* 0b1000110 */ INSN_UNDEFINED,
  /* 0b1000111 */ INSN_UNDEFINED,
  /* 0b1001000 */ INSN_UNDEFINED,
  /* 0b1001001 */ INSN_UNDEFINED,
  /* 0b1001010 */ INSN_UNDEFINED,
  /* 0b1001011 */ INSN_UNDEFINED,
  /* 0b1001100 */ INSN_UNDEFINED,
  /* 0b1001101 */ INSN_UNDEFINED,
  /* 0b1001110 */ INSN_UNDEFINED,
  /* 0b1001111 */ INSN_UNDEFINED,
  /* 0b1010000 */ INSN_UNDEFINED,
  /* 0b1010001 */ INSN_UNDEFINED,
  /* 0b1010010 */ INSN_UNDEFINED,
  /* 0b1010011 */ INSN_UNDEFINED,
  /* 0b1010100 */ INSN_UNDEFINED,
  /* 0b1010101 */ INSN_UNDEFINED,
  /* 0b1010110 */ INSN_UNDEFINED,
  /* 0b1010111 */ INSN_UNDEFINED,
  /* 0b1011000 */ INSN_UNDEFINED,
  /* 0b1011001 */ INSN_UNDEFINED,
  /* 0b1011010 */ INSN_UNDEFINED,
  /* 0b1011011 */ INSN_UNDEFINED,
  /* 0b1011100 */ INSN_UNDEFINED,
  /* 0b1011101 */ INSN_UNDEFINED,
  /* 0b1011110 */ INSN_UNDEFINED,
  /* 0b1011111 */ INSN_UNDEFINED,
  /* 0b1100000 */ INSN_UNDEFINED,
  /* 0b1100001 */ INSN_UNDEFINED,
  /* 0b1100010 */ INSN_UNDEFINED,
  /* 0b1100011 */ INSN_UNDEFINED,
  /* 0b1100100 */ INSN_UNDEFINED,
  /* 0b1100101 */ INSN_UNDEFINED,
  /* 0b1100110 */ INSN_UNDEFINED,
  /* 0b1100111 */ INSN_UNDEFINED,
  /* 0b1101000 */ INSN_UNDEFINED,
  /* 0b1101001 */ INSN_UNDEFINED,
  /* 0b1101010 */ INSN_UNDEFINED,
  /* 0b1101011 */ INSN_UNDEFINED,
  /* 0b1101100 */ INSN_UNDEFINED,
  /* 0b1101101 */ INSN_UNDEFINED,
  /* 0b1101110 */ INSN_UNDEFINED,
  /* 0b1101111 */ INSN_J,
  /* 0b1110000 */ INSN_UNDEFINED,
  /* 0b1110001 */ INSN_UNDEFINED,
  /* 0b1110010 */ INSN_UNDEFINED,
  /* 0b1110011 */ INSN_I,
  /* 0b1110100 */ INSN_UNDEFINED,
  /* 0b1110101 */ INSN_UNDEFINED,
  /* 0b1110110 */ INSN_UNDEFINED,
  /* 0b1110111 */ INSN_UNDEFINED,
  /* 0b1111000 */ INSN_UNDEFINED,
  /* 0b1111001 */ INSN_UNDEFINED,
  /* 0b1111010 */ INSN_UNDEFINED,
  /* 0b1111011 */ INSN_UNDEFINED,
  /* 0b1111100 */ INSN_UNDEFINED,
  /* 0b1111101 */ INSN_UNDEFINED,
  /* 0b1111110 */ INSN_UNDEFINED,
  /* 0b1111111 */ INSN_UNDEFINED
};

class RISCVInstruction {
protected:
  std::string name;

public:
  RISCVInstruction(const char *name) : name(name) {};

  std::string getName() const { return name; }
  virtual operator bool() {
    return true;
  }
  virtual std::ostream&
    operator<<(std::ostream &s);
};

/*
 *  31       25 24     20 19   15 14      12 11   7 6      0
 * ----------------------------------------------------------
 * |  funct7   |   rs2   |  rs1  |  funct3  |  rd  | opcode |
 * ----------------------------------------------------------
 */
class RTypeInstruction : public RISCVInstruction {
public:
  std::uint32_t funct7 : 7;
  std::uint32_t rs2 : 5;
  std::uint32_t rs1 : 5;
  std::uint32_t funct3 : 3;
  std::uint32_t rd : 5;
  std::uint32_t opcode : 7;

  RTypeInstruction(const char *name, std::uint32_t funct7, std::uint32_t rs2,
      std::uint32_t rs1, std::uint32_t funct3, std::uint32_t opcode)
    : RISCVInstruction::RISCVInstruction(name), funct7(funct7),
      rs2(rs2), rs1(rs1), funct3(funct3), opcode(opcode) {};

  RTypeInstruction(const char *name, std::uint32_t insn);

  std::ostream& operator<<(std::ostream &s) {
    s << getName() << " { funct7: " << funct7 << ", rs2: " << rs2 << ", rs1: "
      << rs1 << ", funct3: " << funct3 << ", rd: " << rd << ", opcode: " << opcode
      << " }\n";
    return s;
  }
};

/*
 *  31       25 24     20 19   15 14      12 11   7 6      0
 * ----------------------------------------------------------
 * |      imm[11:0]      |  rs1  |  funct3  |  rd  | opcode |
 * ----------------------------------------------------------
 */
class ITypeInstruction : public RISCVInstruction {
public:
  std::uint32_t imm : 12;
  std::uint32_t rs1 : 5;
  std::uint32_t funct3 : 3;
  std::uint32_t rd : 5;
  std::uint32_t opcode : 7;

  ITypeInstruction(const char *name, std::uint32_t imm, std::uint32_t rs1,
      std::uint32_t funct3, std::uint32_t rd, std::uint32_t opcode)
    : RISCVInstruction::RISCVInstruction(name), imm(imm), rs1(rs1),
      funct3(funct3), rd(rd), opcode(opcode) {};

  ITypeInstruction(const char *name, std::uint32_t insn);

  std::ostream& operator<<(std::ostream &s) {
    s << getName() << " { imm: " << imm << ", rs1: " << rs1 << ", funct3: "
      << funct3 << ", rd: " << rd << ", opcode: " << opcode << " }\n";
    return s;
  }
};

/*
 *  31       25 24     20 19   15 14      12 11         7 6      0
 * ----------------------------------------------------------------
 * | imm[11:5] |   rs2   |  rs1  |  funct3  |  imm[4:0]  | opcode |
 * ----------------------------------------------------------------
 */
class STypeInstruction : public RISCVInstruction {
public:
  std::uint32_t imm : 12;
  std::uint32_t rs2 : 5;
  std::uint32_t rs1 : 5;
  std::uint32_t funct3 : 3;
  std::uint32_t opcode : 7;

  STypeInstruction(const char *name, std::uint32_t imm, std::uint32_t rs2, std::uint32_t rs1,
      std::uint32_t funct3, std::uint32_t opcode)
    : RISCVInstruction::RISCVInstruction(name), imm(imm), rs2(rs2), rs1(rs1),
      funct3(funct3), opcode(opcode) {};

  STypeInstruction(const char *name, std::uint32_t insn);

  std::ostream& operator<<(std::ostream &s) {
    s << getName() << " { imm: " << imm << ", rs2: " << rs2 << ", rs1: " << rs1 << ", funct3: "
      << funct3 << ", opcode: " << opcode << " }\n";
    return s;
  }
};

/*
 *  31           25 24   20 19   15 14      12 11           7 6      0
 * --------------------------------------------------------------------
 * | imm[12][10:5] |  rs2  |  rs1  |  funct3  | imm[4:1][11] | opcode |
 * --------------------------------------------------------------------
 */
class BTypeInstruction : public RISCVInstruction {
public:
  std::uint32_t imm : 12;
  std::uint32_t rs2 : 5;
  std::uint32_t rs1 : 5;
  std::uint32_t funct3 : 3;
  std::uint32_t opcode : 7;

  BTypeInstruction(const char *name, std::uint32_t imm, std::uint32_t rs2, std::uint32_t rs1,
      std::uint32_t funct3, std::uint32_t opcode)
    : RISCVInstruction::RISCVInstruction(name), imm(imm), rs2(rs2), rs1(rs1),
      funct3(funct3), opcode(opcode) {};

  BTypeInstruction(const char *name, std::uint32_t insn);

  std::ostream& operator<<(std::ostream &s) {
    s << getName() << " { imm: " << imm << ", rs2: " << rs2 << ", rs1: " << rs1 << ", funct3: "
      << funct3 << ", opcode: " << opcode << " }\n";
    return s;
  }
};

/*
 *  31           25 24   20 19   15 14      12 11       7 6      0
 * ----------------------------------------------------------------
 * |                imm[31:12]                |    rd    | opcode |
 * ----------------------------------------------------------------
 */
class UTypeInstruction : public RISCVInstruction {
public:
  std::uint32_t imm : 20;
  std::uint32_t rd : 5;
  std::uint32_t opcode : 7;

  UTypeInstruction(const char *name, std::uint32_t imm, std::uint32_t rd, std::uint32_t opcode)
    : RISCVInstruction::RISCVInstruction(name), imm(imm), rd(rd), opcode(opcode) {};

  UTypeInstruction(const char *name, std::uint32_t insn);

  std::ostream& operator<<(std::ostream &s) {
    s << getName() << " { imm: " << imm << ", rd: " << rd
      << ", opcode: " << opcode << " }\n";
    return s;
  }
};

/*
 *  31           25 24   20 19   15 14      12 11       7 6      0
 * ----------------------------------------------------------------
 * |         imm[20][10:1][11][19:12]         |    rd    | opcode |
 * ----------------------------------------------------------------
 */
class JTypeInstruction : public RISCVInstruction {
public:
  std::uint32_t imm : 20;
  std::uint32_t rd : 5;
  std::uint32_t opcode : 7;

  JTypeInstruction(const char *name, std::uint32_t imm, std::uint32_t rd, std::uint32_t opcode)
    : RISCVInstruction::RISCVInstruction(name), imm(imm), rd(rd), opcode(opcode) {};

  JTypeInstruction(const char *name, std::uint32_t insn);

  std::ostream& operator<<(std::ostream &s) {
    s << getName() << " { imm: " << imm << ", rd: " << rd
      << ", opcode: " << opcode << " }\n";
    return s;
  }
};

class InvalidInstruction : public RISCVInstruction {
public:
  InvalidInstruction() : RISCVInstruction::RISCVInstruction("Invalid instruction") { };
  operator bool() override {
    return false;
  }
};

#endif // RISCV_INSN_H