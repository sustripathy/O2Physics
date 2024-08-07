// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

///
/// \file   mcParticle.h
/// \author Nicolò Jacazio nicolo.jacazio@cern.ch
/// \author Francesca Ercolessi francesca.ercolessi@cern.ch
/// \since  31/05/2024
/// \brief  Utilities to handle the MC information
///

#ifndef PWGLF_UTILS_MCPARTICLE_H_
#define PWGLF_UTILS_MCPARTICLE_H_

#include <string>
#include <vector>

#include "ReconstructionDataFormats/PID.h"

namespace o2
{
namespace pwglf
{

/// @brief  Extended the indices of the PID class with additional particles
class PIDExtended
{
 public:
  typedef int16_t ID;

  static constexpr ID Electron = 0;
  static constexpr ID Muon = 1;
  static constexpr ID Pion = 2;
  static constexpr ID Kaon = 3;
  static constexpr ID Proton = 4;
  static constexpr ID Deuteron = 5;
  static constexpr ID Triton = 6;
  static constexpr ID Helium3 = 7;
  static constexpr ID Alpha = 8;
  static constexpr ID PI0 = 9;
  static constexpr ID Photon = 10;
  static constexpr ID K0 = 11;
  static constexpr ID Lambda = 12;
  static constexpr ID HyperTriton = 13;
  static constexpr ID Hyperhydrog4 = 14;
  static constexpr ID XiMinus = 15;
  static constexpr ID OmegaMinus = 16;

  static_assert(Electron == o2::track::PID::Electron, "PID::Electron mismatch");
  static_assert(Muon == o2::track::PID::Muon, "PID::Muon mismatch");
  static_assert(Pion == o2::track::PID::Pion, "PID::Pion mismatch");
  static_assert(Kaon == o2::track::PID::Kaon, "PID::Kaon mismatch");
  static_assert(Proton == o2::track::PID::Proton, "PID::Proton mismatch");
  static_assert(Deuteron == o2::track::PID::Deuteron, "PID::Deuteron mismatch");
  static_assert(Triton == o2::track::PID::Triton, "PID::Triton mismatch");
  static_assert(Helium3 == o2::track::PID::Helium3, "PID::Helium3 mismatch");
  static_assert(Alpha == o2::track::PID::Alpha, "PID::Alpha mismatch");
  static_assert(PI0 == o2::track::PID::PI0, "PID::PI0 mismatch");
  static_assert(Photon == o2::track::PID::Photon, "PID::Photon mismatch");
  static_assert(K0 == o2::track::PID::K0, "PID::K0 mismatch");
  static_assert(Lambda == o2::track::PID::Lambda, "PID::Lambda mismatch");
  static_assert(HyperTriton == o2::track::PID::HyperTriton, "PID::HyperTriton mismatch");
  static_assert(Hyperhydrog4 == o2::track::PID::Hyperhydrog4, "PID::Hyperhydrog4 mismatch");
  static_assert(XiMinus == o2::track::PID::XiMinus, "PID::XiMinus mismatch");
  static_assert(OmegaMinus == o2::track::PID::OmegaMinus, "PID::OmegaMinus mismatch");

  static constexpr ID PIDCounts = 17; // Number of indices defined in PID.h
  static_assert(PIDCounts == o2::track::PID::NIDsTot, "PID::NIDsTot mismatch");

  // Define the antiparticles
  static constexpr ID Positron = 17;
  static constexpr ID MuonPlus = 18;
  static constexpr ID PionMinus = 19;
  static constexpr ID KaonMinus = 20;
  static constexpr ID AntiProton = 21;
  static constexpr ID AntiDeuteron = 22;
  static constexpr ID AntiTriton = 23;
  static constexpr ID AntiHelium3 = 24;
  static constexpr ID AntiAlpha = 25;
  static constexpr ID AntiLambda = 26;
  static constexpr ID AntiHyperTriton = 27;
  static constexpr ID AntiHyperhydrog4 = 28;
  static constexpr ID XiPlus = 29;
  static constexpr ID OmegaPlus = 30;

  static constexpr ID Neutron = 31;
  static constexpr ID AntiNeutron = 32;
  static constexpr ID HyperHelium4 = 33;
  static constexpr ID AntiHyperHelium4 = 34;
  static constexpr ID Phi = 35;

  static constexpr ID BZero = 36;
  static constexpr ID BPlus = 37;
  static constexpr ID BS = 38;
  static constexpr ID D0 = 39;
  static constexpr ID DPlus = 40;
  static constexpr ID DS = 41;
  static constexpr ID DStar = 42;
  static constexpr ID ChiC1 = 43;
  static constexpr ID JPsi = 44;
  static constexpr ID LambdaB0 = 45;
  static constexpr ID LambdaCPlus = 46;
  static constexpr ID OmegaC0 = 47;
  static constexpr ID SigmaC0 = 48;
  static constexpr ID SigmaCPlusPlus = 49;
  static constexpr ID X3872 = 50;
  static constexpr ID Xi0 = 51;
  static constexpr ID XiB0 = 52;
  static constexpr ID XiCCPlusPlus = 53;
  static constexpr ID XiCPlus = 54;
  static constexpr ID XiC0 = 55;
  static constexpr ID NIDsTot = 56;

  static constexpr const char* sNames[NIDsTot + 1] = {
    o2::track::pid_constants::sNames[Electron],     // Electron
    o2::track::pid_constants::sNames[Muon],         // Muon
    o2::track::pid_constants::sNames[Pion],         // Pion
    o2::track::pid_constants::sNames[Kaon],         // Kaon
    o2::track::pid_constants::sNames[Proton],       // Proton
    o2::track::pid_constants::sNames[Deuteron],     // Deuteron
    o2::track::pid_constants::sNames[Triton],       // Triton
    o2::track::pid_constants::sNames[Helium3],      // Helium3
    o2::track::pid_constants::sNames[Alpha],        // Alpha
    o2::track::pid_constants::sNames[PI0],          // PI0
    o2::track::pid_constants::sNames[Photon],       // Photon
    o2::track::pid_constants::sNames[K0],           // K0
    o2::track::pid_constants::sNames[Lambda],       // Lambda
    o2::track::pid_constants::sNames[HyperTriton],  // HyperTriton
    o2::track::pid_constants::sNames[Hyperhydrog4], // Hyperhydrog4
    o2::track::pid_constants::sNames[XiMinus],      // XiMinus
    o2::track::pid_constants::sNames[OmegaMinus],   // OmegaMinus
    "Positron",                                     // Positron
    "MuonPlus",                                     // MuonPlus
    "PionMinus",                                    // PionMinus
    "KaonMinus",                                    // KaonMinus
    "AntiProton",                                   // AntiProton
    "AntiDeuteron",                                 // AntiDeuteron
    "AntiTriton",                                   // AntiTriton
    "AntiHelium3",                                  // AntiHelium3
    "AntiAlpha",                                    // AntiAlpha
    "AntiLambda",                                   // AntiLambda
    "AntiHyperTriton",                              // AntiHyperTriton
    "AntiHyperhydrog4",                             // AntiHyperhydrog4
    "XiPlus",                                       // XiPlus
    "OmegaPlus",                                    // OmegaPlus
    "Neutron",                                      // Neutron
    "AntiNeutron",                                  // AntiNeutron
    "HyperHelium4",                                 // HyperHelium4
    "AntiHyperHelium4",                             // AntiHyperHelium4
    "Phi",                                          // Phi
    "BZero",                                        // BZero
    "BPlus",                                        // BPlus
    "BS",                                           // BS
    "D0",                                           // D0
    "DPlus",                                        // DPlus
    "DS",                                           // DS
    "DStar",                                        // DStar
    "ChiC1",                                        // ChiC1
    "JPsi",                                         // JPsi
    "LambdaB0",                                     // LambdaB0
    "LambdaCPlus",                                  // LambdaCPlus
    "OmegaC0",                                      // OmegaC0
    "SigmaC0",                                      // SigmaC0
    "SigmaCPlusPlus",                               // SigmaCPlusPlus
    "X3872",                                        // X3872
    "Xi0",                                          // Xi0
    "XiB0",                                         // XiB0
    "XiCCPlusPlus",                                 // XiCCPlusPlus
    "XiCPlus",                                      // XiCPlus
    "XiC0",                                         // XiC0
    nullptr};

  static std::vector<std::string> arrayNames()
  {
    std::vector<std::string> names;
    for (int i = 0; i < NIDsTot; i++) {
      names.push_back(sNames[i]);
    }
    return names;
  }

  static const char* getName(ID id) { return sNames[id]; }

  /// \brief Convert PDG code to PID index
  template <typename TrackType>
  static ID pdgToId(const TrackType& particle)
  {
    switch (particle.pdgCode()) {
      case 11:
        return Electron;
      case -11:
        return Positron;
      case 13:
        return Muon;
      case -13:
        return MuonPlus;
      case 211:
        return Pion;
      case -211:
        return PionMinus;
      case 321:
        return Kaon;
      case -321:
        return KaonMinus;
      case 2212:
        return Proton;
      case -2212:
        return AntiProton;
      case 2112:
        return Neutron;
      case -2112:
        return AntiNeutron;
      case o2::constants::physics::Pdg::kDeuteron:
        return Deuteron;
      case -o2::constants::physics::Pdg::kDeuteron:
        return AntiDeuteron;
      case o2::constants::physics::Pdg::kTriton:
        return Triton;
      case -o2::constants::physics::Pdg::kTriton:
        return AntiTriton;
      case o2::constants::physics::Pdg::kHelium3:
        return Helium3;
      case -o2::constants::physics::Pdg::kHelium3:
        return AntiHelium3;
      case o2::constants::physics::Pdg::kAlpha:
        return Alpha;
      case -o2::constants::physics::Pdg::kAlpha:
        return AntiAlpha;
      case o2::constants::physics::Pdg::kHyperHelium4:
        return HyperHelium4;
      case -o2::constants::physics::Pdg::kHyperHelium4:
        return AntiHyperHelium4;
      case 111:
        return PI0;
      case 22:
        return Photon;
      case 130:
        return K0;
      case 3122:
        return Lambda;
      case -3122:
        return AntiLambda;
      case o2::constants::physics::Pdg::kHyperTriton:
        return HyperTriton;
      case -o2::constants::physics::Pdg::kHyperTriton:
        return AntiHyperTriton;
      case o2::constants::physics::Pdg::kHyperHydrogen4:
        return Hyperhydrog4;
      case -o2::constants::physics::Pdg::kHyperHydrogen4:
        return AntiHyperhydrog4;
      case 3312:
        return XiMinus;
      case -3312:
        return XiPlus;
      case 3334:
        return OmegaMinus;
      case -3334:
        return OmegaPlus;
      case o2::constants::physics::Pdg::kPhi:
        return Phi;
      case o2::constants::physics::Pdg::kB0:
        return BZero;
      case o2::constants::physics::Pdg::kBPlus:
        return BPlus;
      case o2::constants::physics::Pdg::kBS:
        return BS;
      case o2::constants::physics::Pdg::kD0:
        return D0;
      case o2::constants::physics::Pdg::kDPlus:
        return DPlus;
      case o2::constants::physics::Pdg::kDS:
        return DS;
      case o2::constants::physics::Pdg::kDStar:
        return DStar;
      case o2::constants::physics::Pdg::kChiC1:
        return ChiC1;
      case o2::constants::physics::Pdg::kJPsi:
        return JPsi;
      case o2::constants::physics::Pdg::kLambdaB0:
        return LambdaB0;
      case o2::constants::physics::Pdg::kLambdaCPlus:
        return LambdaCPlus;
      case o2::constants::physics::Pdg::kOmegaC0:
        return OmegaC0;
      case o2::constants::physics::Pdg::kSigmaC0:
        return SigmaC0;
      case o2::constants::physics::Pdg::kSigmaCPlusPlus:
        return SigmaCPlusPlus;
      case o2::constants::physics::Pdg::kX3872:
        return X3872;
      case o2::constants::physics::Pdg::kXi0:
        return Xi0;
      case o2::constants::physics::Pdg::kXiB0:
        return XiB0;
      case o2::constants::physics::Pdg::kXiCCPlusPlus:
        return XiCCPlusPlus;
      case o2::constants::physics::Pdg::kXiCPlus:
        return XiCPlus;
      case o2::constants::physics::Pdg::kXiC0:
        return XiC0;
      default:
        LOG(debug) << "Cannot identify particle with PDG code " << particle.pdgCode();
        break;
    }
    return -1;
  }
};

} // namespace pwglf
} // namespace o2

#endif // PWGLF_UTILS_MCPARTICLE_H_
