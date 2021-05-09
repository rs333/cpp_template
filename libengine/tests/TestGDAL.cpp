#include "gtest/gtest.h"
#include <gdal_priv.h>
#include <iostream>
#include <string>


class TestGDAL : public ::testing::Test {
  protected:

    int dog=true;	
};

TEST_F(TestGDAL, AInitializedToZero) {
  GDALDataset *poDataset;
  GDALAllRegister();
  std::string filename = "test.tif";
  poDataset = (GDALDataset *)GDALOpen( filename.c_str(), GA_ReadOnly );

  EXPECT_NE(poDataset, nullptr);
  double        adfGeoTransform[6];
  printf( "Driver: %s/%s\n"
      , poDataset->GetDriver()->GetDescription()
      , poDataset->GetDriver()->GetMetadataItem( GDAL_DMD_LONGNAME ) 
      );

  printf( "Size is %dx%dx%d\n"
      , poDataset->GetRasterXSize()
      , poDataset->GetRasterYSize()
      , poDataset->GetRasterCount() 
      );

  if( poDataset->GetProjectionRef()  != NULL ){
    printf( "Projection is `%s'\n", poDataset->GetProjectionRef() );
  }

  if( poDataset->GetGeoTransform( adfGeoTransform ) == CE_None )
  {
    printf( "Origin = (%.6f,%.6f)\n", adfGeoTransform[0], adfGeoTransform[3] );
    printf( "Pixel Size = (%.6f,%.6f)\n", adfGeoTransform[1], adfGeoTransform[5] );
  }

}

