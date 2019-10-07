package jerome.com.usbcamera;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.ImageButton;

import androidx.appcompat.app.AppCompatActivity;

import java.io.IOException;
import java.io.OutputStream;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private ImageButton mCaptureButton;
    private ImageButton mRecordButton;
    private CameraView mUsbCamera;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);


        sd();

        requestWindowFeature(Window.FEATURE_NO_TITLE);

        getWindow().setFlags(
                WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);

        setContentView(R.layout.activity_main);

        mCaptureButton = (ImageButton) findViewById(R.id.capture_btn);
        mCaptureButton.setOnClickListener(this);

        mRecordButton = (ImageButton) findViewById(R.id.record_btn);
        mRecordButton.setOnClickListener(this);

        mUsbCamera = (CameraView) findViewById(R.id.camera_view);
    }

    @Override
    protected void onPause() {
        super.onPause();

        if(mUsbCamera.isVideoRecording()){
            mRecordButton.setImageResource(R.drawable.btn_video);
            mUsbCamera.stopVideoRecord(false);
            int k = 0;
        }
    }

    @Override
    public void onClick(View v) {

        switch (v.getId()) {

            case R.id.capture_btn:
                mUsbCamera.capturePicture();
                break;

            case R.id.record_btn:
                if(mUsbCamera.isVideoRecording()){
                    mRecordButton.setImageResource(R.drawable.btn_video);
                    mUsbCamera.stopVideoRecord(true);
                }else if(mUsbCamera.isCameraReady()){
                    mRecordButton.setImageResource(R.drawable.btn_video_mask);
                    mUsbCamera.startVideoRecord();
                }
                break;
        }
    }


    private void sd(){
        try{
            Process sh = Runtime.getRuntime().exec("su", null,null);
            OutputStream os = sh.getOutputStream();
            os.write(("chmod 666 /dev/video1").getBytes("ASCII"));
            os.flush();
            os.close();
            sh.waitFor();
        }catch (Exception e){
            e.printStackTrace();
        }

    }

}
