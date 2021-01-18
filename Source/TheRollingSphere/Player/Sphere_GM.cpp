// Fill out your copyright notice in the Description page of Project Settings.


#include "Sphere_GM.h"
#include "PlayerSphere.h"

ASphere_GM::ASphere_GM()
{
	DefaultPawnClass = APlayerSphere::StaticClass();
}