from launch_ros.actions import Node

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, TimerAction
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration, PythonExpression


def generate_launch_description():

	turtlesim_node=Node(
    	package='turtlesim',
    	# namespace='turtlesim1',
    	executable='turtlesim_node',
    	name='turtlesim_node',
		)
	
	micro_ros_agent=ExecuteProcess(
		cmd=[[
			'ros2 run micro_ros_agent micro_ros_agent udp4 --port 8888'
		]],
		shell=True,
		output='screen'
	)


	return LaunchDescription(
		[
			turtlesim_node,
			micro_ros_agent,
		]
	)