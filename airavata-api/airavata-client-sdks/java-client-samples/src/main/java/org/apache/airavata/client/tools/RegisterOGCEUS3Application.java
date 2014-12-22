package org.apache.airavata.client.tools;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.apache.airavata.api.Airavata;
import org.apache.airavata.api.client.AiravataClientFactory;
import org.apache.airavata.model.appcatalog.appdeployment.ApplicationParallelismType;
import org.apache.airavata.model.appcatalog.appinterface.DataType;
import org.apache.airavata.model.appcatalog.appinterface.InputDataObjectType;
import org.apache.airavata.model.appcatalog.appinterface.OutputDataObjectType;
import org.apache.airavata.model.appcatalog.computeresource.ComputeResourceDescription;
import org.apache.airavata.model.appcatalog.computeresource.JobManagerCommand;
import org.apache.airavata.model.appcatalog.computeresource.ResourceJobManager;
import org.apache.airavata.model.appcatalog.computeresource.ResourceJobManagerType;
import org.apache.airavata.model.appcatalog.computeresource.SCPDataMovement;
import org.apache.airavata.model.appcatalog.computeresource.SSHJobSubmission;
import org.apache.airavata.model.appcatalog.computeresource.SecurityProtocol;
import org.apache.airavata.model.appcatalog.gatewayprofile.ComputeResourcePreference;
import org.apache.airavata.model.appcatalog.gatewayprofile.GatewayResourceProfile;
import org.apache.airavata.model.error.AiravataClientException;
import org.apache.thrift.TException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class RegisterOGCEUS3Application {
	
	private final static Logger logger = LoggerFactory.getLogger(RegisterSampleApplications.class);
    
//	public static final String THRIFT_SERVER_HOST = "gridfarm005.ucs.indiana.edu";
//  public static final int THRIFT_SERVER_PORT = 8930;
	private static final String DEFAULT_GATEWAY= "default"; 
	public static final String THRIFT_SERVER_HOST = "localhost";
	public static final int THRIFT_SERVER_PORT = 8930;
//    private static final String DEFAULT_GATEWAY = "ultrascan";
    private static Airavata.Client airavataClient;

    //Host Id's
    private static String stampedeResourceId = "stampede.tacc.xsede.org_af57850b-103b-49a1-aab2-27cb070d3bd9";
    private static String trestlesResourceId = "trestles.sdsc.xsede.org_1ccc526f-ab74-4a5a-970a-c464cb9def5a";
//    private static String lonestarResourceId = "lonestar.tacc.teragrid.org_2e0273bc-324b-419b-9786-38a360d44772";
//    private static String alamoResourceId = "alamo.uthscsa.edu_7b6cf99a-af2e-4e8b-9eff-998a5ef60fe5";
    
    private static String ultrascanModuleId = "ultrascan_f8e80bc9-c0da-48d8-bb2a-30fe7e3fbab6";
    private static String ultrascanAppId = "ultrascan_e76ab5cf-79f6-44df-a244-10a734183fec";
    
    public static void main(String[] args) {
        try {
			airavataClient = AiravataClientFactory.createAiravataClient(THRIFT_SERVER_HOST, THRIFT_SERVER_PORT);
			System.out.println("API version is " + airavataClient.getAPIVersion());

			//Register all compute hosts
			registerXSEDEHosts();
			
			// Register Gateway Details
			registerGatewayResourceProfile();
		
			//Register module
			registerAppModules();
			
			//Register Application
			registerUltrascanInterface();
			
			//Register Deployment 
			registerApplicationDeployment();
	
			// update 
//			updateXSEDEHosts();

        } catch (Exception e) {
            logger.error("Error while connecting with server", e.getMessage());
            e.printStackTrace();
        }

	}
    public static void registerXSEDEHosts() {
        try {
            System.out.println("\n #### Registering XSEDE Computational Resources #### \n");

            //Register Stampede
            stampedeResourceId = registerComputeHost("stampede.tacc.xsede.org", "TACC Stampede Cluster",
                    ResourceJobManagerType.SLURM, "push", "/usr/bin", SecurityProtocol.GSI, 2222, "/usr/local/bin/ibrun");
            System.out.println("Stampede Resource Id is " + stampedeResourceId);

            //Register Trestles
            trestlesResourceId = registerComputeHost("trestles.sdsc.xsede.org", "SDSC Trestles Cluster",
                    ResourceJobManagerType.PBS, "push", "/opt/torque/bin/", SecurityProtocol.GSI, 22, "/opt/mvapich2/pgi/ib/bin/mpiexec -np");
            System.out.println("Trestles Resource Id is " + trestlesResourceId);
            
            //Register Lonestar
//            lonestarResourceId = registerComputeHost("lonestar.tacc.teragrid.org", "TACC Lonestar Cluster",
//                    ResourceJobManagerType.UGE, "push", "/opt/sge6.2/bin/lx24-amd64", SecurityProtocol.GSI, 22, "/sge_common/default/pe_scripts/ibrun");
//            System.out.println("Lonestar Resource Id is " + lonestarResourceId);
//
//            //Register Alamo
//            alamoResourceId = registerComputeHost("alamo.uthscsa.edu", "Alamo Cluster",
//                    ResourceJobManagerType.PBS, "push", "/opt/torque/bin/", SecurityProtocol.SSH_KEYS, 22, "/share/apps/openmpi/bin/mpiexec - n" );
//            System.out.println("Alamo Cluster " + alamoResourceId);

        } catch (TException e) {
            e.printStackTrace();
        }

    }
    public static void updateXSEDEHosts() {
        try {
            System.out.println("\n #### Registering XSEDE Computational Resources #### \n");

            //Register Stampede
            stampedeResourceId = updateComputeHost( stampedeResourceId,"stampede.tacc.xsede.org", "TACC Stampede Cluster",
                    ResourceJobManagerType.SLURM, "push", "/usr/bin", SecurityProtocol.GSI, 2222, "/usr/local/bin/ibrun");
            System.out.println("Stampede Resource Id is " + stampedeResourceId);

            //Register Trestles
            trestlesResourceId = updateComputeHost(trestlesResourceId,"trestles.sdsc.xsede.org", "SDSC Trestles Cluster",
                    ResourceJobManagerType.PBS, "push", "/opt/torque/bin/", SecurityProtocol.GSI, 22, "/opt/mvapich2/pgi/ib/bin/mpiexec -np");
            System.out.println("Trestles Resource Id is " + trestlesResourceId);
            
            //Register Lonestar
//            lonestarResourceId = updateComputeHost(lonestarResourceId,"lonestar.tacc.teragrid.org", "TACC Lonestar Cluster",
//                    ResourceJobManagerType.UGE, "push", "/opt/sge6.2/bin/lx24-amd64", SecurityProtocol.GSI, 22, "/sge_common/default/pe_scripts/ibrun");
//            System.out.println("Lonestar Resource Id is " + lonestarResourceId);
//
//            //Register Alamo
//            alamoResourceId = updateComputeHost(alamoResourceId,"alamo.uthscsa.edu", "Alamo Cluster",
//                    ResourceJobManagerType.PBS, "push", "/opt/torque/bin/", SecurityProtocol.SSH_KEYS, 22, "/share/apps/openmpi/bin/mpiexec -n");
//            System.out.println("Alamo Cluster " + alamoResourceId);

        } catch (TException e) {
            e.printStackTrace();
        }

    }
    public static void registerAppModules() {
        try {
            System.out.println("\n #### Registering Application Modules #### \n");

            //Register Echo
            ultrascanModuleId = airavataClient.registerApplicationModule(
                    RegisterSampleApplicationsUtils.createApplicationModule(
                            "ultrascan_ogce", "1.0", "ultrascan application"));
            System.out.println("Ultrascan Module Id " + ultrascanModuleId);
        }catch(Exception e){
        	e.getLocalizedMessage();
        }
    }
    public static void registerUltrascanInterface() {
        try {
            System.out.println("#### Registering Ultrascan Interface #### \n");

            List<String> appModules = new ArrayList<String>();
            appModules.add(ultrascanModuleId);

            InputDataObjectType input1 = RegisterSampleApplicationsUtils.createAppInput("input", null,
                    DataType.URI, null, 1,null, null, false, "input tar file", null);
           
            List<InputDataObjectType> applicationInputs = new ArrayList<InputDataObjectType>();
            applicationInputs.add(input1);

            OutputDataObjectType output1 = RegisterSampleApplicationsUtils.createAppOutput("output",
                    "", DataType.URI, null, null);

//            OutputDataObjectType output2 = RegisterSampleApplicationsUtils.createAppOutput("stdout",
//                    "", DataType.URI);
//            OutputDataObjectType output3 = RegisterSampleApplicationsUtils.createAppOutput("stderr",
//                    "", DataType.URI);

            List<OutputDataObjectType> applicationOutputs = new ArrayList<OutputDataObjectType>();
            applicationOutputs.add(output1);
  
            ultrascanAppId = airavataClient.registerApplicationInterface(
                    RegisterSampleApplicationsUtils.createApplicationInterfaceDescription("ultrascan", "ultrascan application",
                            appModules, applicationInputs, applicationOutputs));
            System.out.println("Ultrascan Application Interface Id " + ultrascanAppId);

        } catch (TException e) {
            e.printStackTrace();
        }
    }

	public static void registerApplicationDeployment() {
		try {
			System.out.println("#### Registering Application Deployments on Stampede #### \n");

			// Register Stampede
			String ultascanStamplede = airavataClient.registerApplicationDeployment(RegisterSampleApplicationsUtils.createApplicationDeployment(ultrascanModuleId,
					stampedeResourceId, "/home1/01437/ogce/xsede_apps/ultrascan/bin/us_mpi_analysis", ApplicationParallelismType.MPI, "ultrascan OGCE application", null));
			System.out.println("Ultrascan on stampede deployment Id " + ultascanStamplede);
			
			String ultascanTrestles = airavataClient.registerApplicationDeployment(RegisterSampleApplicationsUtils.createApplicationDeployment(ultrascanModuleId,
					trestlesResourceId, "/home/ogce/xsede_app/ultrascan/bin/us_mpi_analysis", ApplicationParallelismType.MPI, "ultrascan OGCE application", null));
			System.out.println("Ultrascan on trestles deployment Id " + ultascanTrestles);
//			String ultascanLonestar = airavataClient.registerApplicationDeployment(RegisterSampleApplicationsUtils.createApplicationDeployment(ultrascanModuleId,
//					lonestarResourceId, "/home1/01623/us3/bin/us_mpi_analysis", ApplicationParallelismType.MPI, "ultrascan application"));
//			System.out.println("Ultrascan on lonestar deployment Id " + ultascanLonestar);
//			String ultascanAlamo = airavataClient.registerApplicationDeployment(RegisterSampleApplicationsUtils.createApplicationDeployment(ultrascanModuleId,
//					alamoResourceId, "/home/us3/bin/us_mpi_analysis.sh", ApplicationParallelismType.MPI, "ultrascan application"));
//			System.out.println("Ultrascan on alamo deployment Id " + ultascanAlamo);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	public static void registerGatewayResourceProfile() {

        try {
            System.out.println("#### Registering Gateway proflie #### \n");


            ComputeResourcePreference stampedeResourcePreferences = RegisterSampleApplicationsUtils.
                    createComputeResourcePreference(stampedeResourceId, "TG-STA110014S", false, null, null, null,
                            "/scratch/01437/ogce/ultrascan_testing/");

            ComputeResourcePreference trestlesResourcePreferences = RegisterSampleApplicationsUtils.
                    createComputeResourcePreference(trestlesResourceId, "sds128", false, null, null, null,
                            "/oasis/scratch/trestles/ogce/temp_project/gta-work-dirs/");

//            ComputeResourcePreference lonestarResourcePreferences = RegisterSampleApplicationsUtils.
//                    createComputeResourcePreference(lonestarResourceId, "ULTRASCAN", false, null, null, null,
//                            "/scratch/01623/us3/airavata/");
//            
//            ComputeResourcePreference alamoResourcePreferences = RegisterSampleApplicationsUtils.
//                    createComputeResourcePreference(alamoResourceId, null, false, null, null, null,
//                            "/mnt/glusterfs/work/");

            GatewayResourceProfile gatewayResourceProfile = new GatewayResourceProfile();
            gatewayResourceProfile.setGatewayName(DEFAULT_GATEWAY);
            gatewayResourceProfile.addToComputeResourcePreferences(stampedeResourcePreferences);
            gatewayResourceProfile.addToComputeResourcePreferences(trestlesResourcePreferences);
  //          gatewayResourceProfile.addToComputeResourcePreferences(lonestarResourcePreferences);
  //          gatewayResourceProfile.addToComputeResourcePreferences(alamoResourcePreferences);

            String gatewayProfile = airavataClient.registerGatewayResourceProfile(gatewayResourceProfile);
            System.out.println("Gateway Profile is registered with Id " + gatewayProfile);

        } catch (TException e) {
            e.printStackTrace();
        }
    }
	public static String registerComputeHost(String hostName, String hostDesc, ResourceJobManagerType resourceJobManagerType, String monitoringEndPoint,
			String jobMangerBinPath, SecurityProtocol securityProtocol, int portNumber, String jobManagerCommand) throws TException {

		ComputeResourceDescription computeResourceDescription = RegisterSampleApplicationsUtils
				.createComputeResourceDescription(hostName, hostDesc, null, null);

		String computeResourceId = airavataClient.registerComputeResource(computeResourceDescription);

		if (computeResourceId.isEmpty())
			throw new AiravataClientException();

		ResourceJobManager resourceJobManager = RegisterSampleApplicationsUtils.createResourceJobManager(resourceJobManagerType, monitoringEndPoint,
				jobMangerBinPath, null);

		if (jobManagerCommand != null) {
			Map<JobManagerCommand, String> jobManagerCommandStringMap = new HashMap<JobManagerCommand, String>();
			jobManagerCommandStringMap.put(JobManagerCommand.SUBMISSION, jobManagerCommand);
			resourceJobManager.setJobManagerCommands(jobManagerCommandStringMap);
		}
		SSHJobSubmission sshJobSubmission = new SSHJobSubmission();
		sshJobSubmission.setResourceJobManager(resourceJobManager);
		sshJobSubmission.setSecurityProtocol(securityProtocol);
		sshJobSubmission.setSshPort(portNumber);
		airavataClient.addSSHJobSubmissionDetails(computeResourceId, 1, sshJobSubmission);

		SCPDataMovement scpDataMovement = new SCPDataMovement();
		scpDataMovement.setSecurityProtocol(securityProtocol);
		scpDataMovement.setSshPort(portNumber);
		airavataClient.addSCPDataMovementDetails(computeResourceId, 1, scpDataMovement);

		return computeResourceId;
	}
	public static String updateComputeHost( String computeResourceId, String hostName, String hostDesc, ResourceJobManagerType resourceJobManagerType, String monitoringEndPoint,
			String jobMangerBinPath, SecurityProtocol securityProtocol, int portNumber, String jobManagerCommand) throws TException {

		if (computeResourceId.isEmpty())
			throw new AiravataClientException();

		ResourceJobManager resourceJobManager = RegisterSampleApplicationsUtils.createResourceJobManager(resourceJobManagerType, monitoringEndPoint,
				jobMangerBinPath, null);

		if (jobManagerCommand != null) {
			Map<JobManagerCommand, String> jobManagerCommandStringMap = new HashMap<JobManagerCommand, String>();
			jobManagerCommandStringMap.put(JobManagerCommand.SUBMISSION, jobManagerCommand);
			resourceJobManager.setJobManagerCommands(jobManagerCommandStringMap);
		}
		SSHJobSubmission sshJobSubmission = new SSHJobSubmission();
		sshJobSubmission.setResourceJobManager(resourceJobManager);
		sshJobSubmission.setSecurityProtocol(securityProtocol);
		sshJobSubmission.setSshPort(portNumber);
		airavataClient.addSSHJobSubmissionDetails(computeResourceId, 1, sshJobSubmission);
		ComputeResourceDescription computeResourceDescription = airavataClient.getComputeResource(computeResourceId);
		computeResourceDescription.getJobSubmissionInterfacesIterator();
		SCPDataMovement scpDataMovement = new SCPDataMovement();
		scpDataMovement.setSecurityProtocol(securityProtocol);
		scpDataMovement.setSshPort(portNumber);
		airavataClient.addSCPDataMovementDetails(computeResourceId, 1, scpDataMovement);

		return computeResourceId;
	}
}
