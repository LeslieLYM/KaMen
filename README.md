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
* 13 (KaMenMaskMaster) Created IsHooked to determine whether there is hook above certain height
* 14 Created HookToAttach class, HookToAttach BP
* 15 Created PuppetPawn class, BP, Ready for swapping pawn in Player Controller
* 16 (MainPlayerController) Spawn Kamen Pawn, Puppet Pawn at start,
        Created Get KamenPawn, Get PuppetPawn
        Tried to swap possession of Pawns
* 17 (MainPlayerController) Created IntendSwitchPawn to swap possession of pawns 
* 18 Created PuppetStaticMeshComponent, Ready PuppetPawn to perform actions
* 19 (PuppetPawn, PuppetStaticMeshComponent) Ready functions
        (PuppetPawn) Attached PuppetStaticMeshComponent
* 20 (MainPlayerController) Set switch pawn locations
