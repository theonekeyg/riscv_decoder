#include "riscv_decode.h"
#include "riscv_insn.h"
#include "decoder_hooks.h"

int riscv_decode(struct riscv_insn *insn, uint32_t repr) {
  uint32_t opcode = repr & 0b1111111;
  switch (OPCODE_TYPES_TABLE[opcode]) {
    case INSN_R:
      for (int i = 0; i < sizeof(decoder_hooks) / sizeof(*decoder_hooks); ++i) {
        if (decoder_hooks[i].riscv_decode_r(insn, repr, opcode)) {
          return insn->kind;
        }
      }
      break;
    case INSN_I:
      for (int i = 0; i < sizeof(decoder_hooks) / sizeof(*decoder_hooks); ++i) {
        if (decoder_hooks[i].riscv_decode_i(insn, repr, opcode)) {
          return insn->kind;
        }
      }
      break;
    case INSN_S:
      for (int i = 0; i < sizeof(decoder_hooks) / sizeof(*decoder_hooks); ++i) {
        if (decoder_hooks[i].riscv_decode_s(insn, repr, opcode)) {
          return insn->kind;
        }
      }
      break;
    case INSN_B:
      for (int i = 0; i < sizeof(decoder_hooks) / sizeof(*decoder_hooks); ++i) {
        if (decoder_hooks[i].riscv_decode_b(insn, repr, opcode)) {
          return insn->kind;
        }
      }
      break;
    case INSN_U:
      for (int i = 0; i < sizeof(decoder_hooks) / sizeof(*decoder_hooks); ++i) {
        if (decoder_hooks[i].riscv_decode_u(insn, repr, opcode)) {
          return insn->kind;
        }
      }
      break;
    case INSN_J:
      for (int i = 0; i < sizeof(decoder_hooks) / sizeof(*decoder_hooks); ++i) {
        if (decoder_hooks[i].riscv_decode_j(insn, repr, opcode)) {
          return insn->kind;
        }
      }
      break;
  }
  insn->kind = KIND_ILLEGAL;
  return insn->kind;
}

int riscv_decode_rv32i_r(struct riscv_insn *insn, uint32_t repr, uint32_t opcode) {
  uint32_t funct7 = (repr >> 25) & 0b1111111;
  uint32_t funct3 = (repr >> 12) & 0b111;
  switch (funct3) {
    case 0:
      if (funct7 == 0b0000000) {
        riscv_decode_r(insn, KIND_ADD, repr, opcode);
        return 1;
      } else if (funct7 == 0b0100000) {
        riscv_decode_r(insn, KIND_SUB, repr, opcode);
        return 1;
      }
      break;
    case 0b001:
      riscv_decode_r(insn, KIND_SLL, repr, opcode);
      return 1;
    case 0b010:
      riscv_decode_r(insn, KIND_SLT, repr, opcode);
      return 1;
    case 0b011:
      riscv_decode_r(insn, KIND_SLTU, repr, opcode);
      return 1;
    case 0b100:
      riscv_decode_r(insn, KIND_XOR, repr, opcode);
      return 1;
    case 0b101:
      if (funct7 == 0b0000000) {
        riscv_decode_r(insn, KIND_SRL, repr, opcode);
        return 1;
      } else if (funct7 == 0b0100000) {
        riscv_decode_r(insn, KIND_SRA, repr, opcode);
        return 1;
      }
      break;
    case 0b110:
      riscv_decode_r(insn, KIND_OR, repr, opcode);
      return 1;
    case 0b111:
      riscv_decode_r(insn, KIND_AND, repr, opcode);
      return 1;
  }
  return 0;
}

int riscv_decode_rv32i_i(struct riscv_insn *insn, uint32_t repr, uint32_t opcode) {
  uint32_t funct3 = (repr >> 12) & 0b111;
  switch (opcode) {
    case 0b1100111:
      riscv_decode_i(insn, KIND_JALR, repr, opcode);
      return 1;
    case 0b0000011:
      switch (funct3) {
        case 0b000:
          riscv_decode_i(insn, KIND_LB, repr, opcode);
          return 1;
        case 0b001:
          riscv_decode_i(insn, KIND_LH, repr, opcode);
          return 1;
        case 0b010:
          riscv_decode_i(insn, KIND_LW, repr, opcode);
          return 1;
        case 0b100:
          riscv_decode_i(insn, KIND_LBU, repr, opcode);
          return 1;
        case 0b101:
          riscv_decode_i(insn, KIND_LHU, repr, opcode);
          return 1;
      }
      break;
    case 0b0010011:
      switch (funct3) {
        case 0b000:
          riscv_decode_i(insn, KIND_ADDI, repr, opcode);
          return 1;
        case 0b010:
          riscv_decode_i(insn, KIND_SLTI, repr, opcode);
          return 1;
        case 0b011:
          riscv_decode_i(insn, KIND_SLTIU, repr, opcode);
          return 1;
        case 0b100:
          riscv_decode_i(insn, KIND_XORI, repr, opcode);
          return 1;
        case 0b110:
          riscv_decode_i(insn, KIND_ORI, repr, opcode);
          return 1;
        case 0b111:
          riscv_decode_i(insn, KIND_ANDI, repr, opcode);
          return 1;
      }
    case 0b0001111:
      riscv_decode_i(insn, KIND_FENCE, repr, opcode);
      return 1;
    case 0b1110011: {
      uint32_t imm = (repr >> 20) && 0b1111111;
      if (imm) {
        riscv_decode_i(insn, KIND_EBREAK, repr, opcode);
        return 1;
      }
      riscv_decode_i(insn, KIND_ECALL, repr, opcode);
      return 1;
    }
  }
  return 0;
}

int riscv_decode_rv32i_s(struct riscv_insn *insn, uint32_t repr, uint32_t opcode) {
}

int riscv_decode_rv32i_b(struct riscv_insn *insn, uint32_t repr, uint32_t opcode) {
}

int riscv_decode_rv32i_u(struct riscv_insn *insn, uint32_t repr, uint32_t opcode) {
}

int riscv_decode_rv32i_j(struct riscv_insn *insn, uint32_t repr, uint32_t opcode) {
}

int riscv_decode_rv64i_r(struct riscv_insn *insn, uint32_t repr, uint32_t opcode) {
}

int riscv_decode_rv64i_i(struct riscv_insn *insn, uint32_t repr, uint32_t opcode) {
}

int riscv_decode_rv64i_s(struct riscv_insn *insn, uint32_t repr, uint32_t opcode) {
}

int riscv_decode_rv64i_b(struct riscv_insn *insn, uint32_t repr, uint32_t opcode) {
}

int riscv_decode_rv64i_u(struct riscv_insn *insn, uint32_t repr, uint32_t opcode) {
}

int riscv_decode_rv64i_j(struct riscv_insn *insn, uint32_t repr, uint32_t opcode) {
}
