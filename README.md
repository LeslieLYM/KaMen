# KaMen

* 01 Created Repository
* 02 Connected the Project
* 03 Created GameMode class, Pawn Classes, Player Controller Classes
* 04 Set KamenStaticMeshComponent Reference, Ready to add velocity to Mesh
* 05 (KaMenStaticMesh) Created Get Initial Kamen Component RightVector, Rotate, Set Movement 
        (KaMenPawn) Created Intend Right to Move the character, Determine whether rotation is needed for the current input
* 06 (KaMenPawn) Created Intend Jump, JumpTrace timer function, IsGround check using SweepSingleByObjectType
        (KaMenStaticMesh) Created AdjustRotation, Jump
* 07 Created MaskMasterComponent, Mask1 child, MaskStaticMeshComponent class
        Plugged MaskMaster to Pawn,
        Added Equip input for Mask 1, called CheckMask Function 
* 08 (KaMenMaskMaster) Created CheckMask to equip correct masks
        (KaMenMaskStaticMesh) Created Transform, set static mesh to KaMenStaticMesh
* 09 (KaMenMaskStaticMesh) Created ThrowString(),
        (KaMenPawn) Created SetKamenMaskMReference(), UsePrimarySkill()
* 10 (KaMenMaskMaster) Created GetCurrentMaskState()
* 11 Created virtual UsePrimarySkill, overriden by child class (KaMenMask1_C)
* 12 Called PrimarySkills from user to the MaskStaticMesh through MaskMaster
