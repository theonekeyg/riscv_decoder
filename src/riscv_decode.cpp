#include "riscv_decode.hpp"
#include "riscv_insn.hpp"

RISCVInstruction RISCVDecoder::decode(std::uint32_t insn) {
  std::uint32_t opcode = insn & 0b1111111;
  switch (OPCODE_TYPES_TABLE[opcode]) {
    case INSN_R:
      for (auto decoder : decoders) {
        std::optional<RTypeInstruction> decoded_insn
          = decoder.decodeRType(insn, opcode);
        if (decoded_insn) {
          return decoded_insn.value();
        }
      }
      break;
    case INSN_I:
      for (auto decoder : decoders) {
        std::optional<ITypeInstruction> decoded_insn
          = decoder.decodeIType(insn, opcode);
        if (decoded_insn) {
          return decoded_insn.value();
        }
      }
      break;
    case INSN_S:
      for (auto decoder : decoders) {
        std::optional<STypeInstruction> decoded_insn
          = decoder.decodeSType(insn, opcode);
        if (decoded_insn) {
          return decoded_insn.value();
        }
      }
      break;
    case INSN_B:
      for (auto decoder : decoders) {
        std::optional<BTypeInstruction> decoded_insn
          = decoder.decodeBType(insn, opcode);
        if (decoded_insn) {
          return decoded_insn.value();
        }
      }
      break;
    case INSN_U:
      for (auto decoder : decoders) {
        std::optional<UTypeInstruction> decoded_insn
          = decoder.decodeUType(insn, opcode);
        if (decoded_insn) {
          return decoded_insn.value();
        }
      }
      break;
    case INSN_J:
      for (auto decoder : decoders) {
        std::optional<JTypeInstruction> decoded_insn
          = decoder.decodeJType(insn, opcode);
        if (decoded_insn) {
          return decoded_insn.value();
        }
      }
      break;
  }
  return InvalidInstruction();
}

std::optional<RTypeInstruction> RV32IDecoder::decodeRType(
    std::uint32_t insn, std::uint32_t opcode) {
  std::uint32_t funct7 = (insn >> 25) & 0b1111111;
  std::uint32_t funct3 = (insn >> 12) & 0b111;
  switch (funct3) {
    case 0:
      if (funct7 == 0b0000000) {
        return std::optional(ADD("ADD", insn));
      } else if (funct7 == 0b0100000) {
        return std::optional(SUB("SUB", insn));
      }
      break;
    case 0b001:
      return std::optional(SLL("SLL", insn));
    case 0b010:
      return std::optional(SLT("SLT", insn));
    case 0b011:
      return std::optional(SLTU("SLTU", insn));
    case 0b100:
      return std::optional(XOR("XOR", insn));
    case 0b101:
      if (funct7 == 0b0000000) {
        return std::optional(SRL("SRL", insn));
      } else if (funct7 == 0b0100000) {
        return std::optional(SRA("SRA", insn));
      }
      break;
    case 0b110:
      return std::optional(OR("OR", insn));
    case 0b111:
      return std::optional(AND("AND", insn));
  }
  return std::optional<RTypeInstruction>();
}

std::optional<ITypeInstruction> RV32IDecoder::decodeIType(
    std::uint32_t insn, std::uint32_t opcode) {
  std::uint32_t funct3 = (insn >> 12) & 0b111;
  switch (opcode) {
    case 0b1100111:
      return std::optional(JALR("JALR", insn));
    case 0b0000011:
      switch (funct3) {
        case 0b000:
          return std::optional(LB("LB", insn));
        case 0b001:
          return std::optional(LH("LH", insn));
        case 0b010:
          return std::optional(LW("LW", insn));
        case 0b100:
          return std::optional(LBU("LBU", insn));
        case 0b101:
          return std::optional(LHU("LHU", insn));
      }
      break;
  }
  return std::optional<ITypeInstruction>();
}

std::optional<STypeInstruction> RV32IDecoder::decodeSType(
    std::uint32_t insn, std::uint32_t opcode) {
  return std::optional<STypeInstruction>();
}

std::optional<BTypeInstruction> RV32IDecoder::decodeBType(
    std::uint32_t insn, std::uint32_t opcode) {
  return std::optional<BTypeInstruction>();
}

std::optional<UTypeInstruction> RV32IDecoder::decodeUType(
    std::uint32_t insn, std::uint32_t opcode) {
  return std::optional<UTypeInstruction>();
}

std::optional<JTypeInstruction> RV32IDecoder::decodeJType(
    std::uint32_t insn, std::uint32_t opcode) {
  return std::optional<JTypeInstruction>();
}