// Copyright (C) 2006 Mancuso Raffaele
// This file is part of the "IrrNewt library".
// For conditions of distribution and use, see copyright notice in IrrNewt.hpp

#ifndef IRRNEWT_FRAMEWORK_MATERIAL_PAIR_HPP_416516816AVAVASDAWDW651686SDBRHSTSADFAWQEW
#define IRRNEWT_FRAMEWORK_MATERIAL_PAIR_HPP_416516816AVAVASDAWDW651686SDBRHSTSADFAWQEW
#pragma once

#include <stddef.h>
#include <stdio.h>//NULL declaration

#include <irrlicht.h>
#include <Newton.h>

#include "dll_exports.hpp"

namespace irr{
	namespace newton{

		//!\brief a pair of materials.
		//!
		//!Used only in material callbacks (when two materials contact)
		//!The function of this class can only be called inside a material callback
		//!ALL DOCUMENTATIONS OF THE FUNCTIONS ARE TAKEN FROM NEWTON DOCUMENTATION
		class IRRNEWT_API IMaterialPair{
			NewtonMaterial* newton_material_pair;
		public:

			//!constructor, don't call directly
			IMaterialPair():newton_material_pair(NULL){}

			//!constructor, don't call directly
			IMaterialPair(NewtonMaterial* material_to_set):newton_material_pair(material_to_set) {}

			//!deconstructor
			~IMaterialPair() {}

			//!get newton material
			//!\return newton material
			inline NewtonMaterial* getNewtonMaterialPair() {return newton_material_pair;}

			//functions
			//!Override the default elasticity (coefficient of restitution) value for the contact
			//!\param value new elasticity
			void setContactElasticity(irr::f32 value);

			//functions
			//!Override the default softness value for the contact
			//!\param value new softness
			void setContactSoftness(irr::f32 value);

			//!Enable or disable friction calculation for this contact.
			//!\param state new state. 0 makes the contact frictionless along the index tangent vector
			//!\param index index to the tangent vector. 0 for primary tangent vector or 1 for the secondary tangent vector.
			//!\return none
			void setContactFrictionState(
				irr::s32 state,
				bool index);

			//!Disable processing for the contact
			//!\return none
			void disableContact();

			//!Return the face attribute assigned to this face when for a user defined collision or a Newton collision tree
			//!this function can be used by the application to retrieve the face id of a polygon for a collision tree
			//!\return face attribute for collision trees. Zero if the contact was generated by two convex collisions.
			unsigned getContactFaceAttribute();

			//!Get the current time step. This function can be useful for the implementation of powered contacts.
			//!\return the current time step
			irr::f32 getCurrentTimeStep();

			//!Get the contact force vector in global space
			//!The contact force value is only valid when calculating resting contacts.
			//!This means if two bodies collide with non zero relative velocity,
			//!the reaction force will be an impulse, which is not a reaction force,
			//!this will return zero vector. this function will only return meaningful values
			//!when the colliding bodies are at rest.
			//!\return the contact force vector
			irr::core::vector3df getContactForce();

			//!Get the contact position in global space
			//!\return contact position
			//!\see getContactNormal()
			irr::core::vector3df getContactPosition();

			//!Get the contact normal in global space
			//!\return contact narmal
			//!\see getContactPosition()
			irr::core::vector3df getContactNormal();

			//!Get the contact tangent vector to the contact point
			//!\param primary reference to a vector to hold the primary tangent vector
			//!\param secondary reference to a vector to hold the secondary tangent vector
			//!\return none
			void getContactTangentDirections(
				irr::core::vector3df& primary,
				irr::core::vector3df& secondary);

		};
	}
}

#endif